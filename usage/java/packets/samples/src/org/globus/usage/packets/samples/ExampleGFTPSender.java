package org.globus.usage.packets.samples;

import java.util.Calendar;
import java.util.Date;
import java.util.Properties;

import org.globus.usage.packets.GFTPMonitorPacket;

public class ExampleGFTPSender {

    private int port = 0;
    private InetAddress[] addressArray = null;
    private DatagramSocket socket = null;

    private static Category log =
        Category.getInstance(ExampleGFTPSender.class.getName());

    public ExampleGFTPSender() throws SocketException { 

        socket = new DatagramSocket(); //no port specifier needed
        /*after calling this constructor, call readPropertiesFile or
        readCommandLine to set port and addresses.*/
    }

    /*Function to send a GridFTPusage packet with all the given data*/
    public void sendPacket(byte opType, Date start, Date end,
                           long bytes, long stripes, long streams,
                           long bufferSize, long blockSize, long ftpReturn,
                           String gftpVersion) {

        GFTPMonitorPacket pack = new GFTPMonitorPacket();
        
        try {
            pack.setOperationType (opType);
            pack.setStartTime(start);
            pack.setEndTime(end) ;
            pack.setNumBytes(bytes) ;
            pack.setNumStripes(stripes) ;
            pack.setNumStreams(streams) ;
            pack.setBufferSize(bufferSize);
            pack.setBlockSize(blockSize);
            pack.setFTPReturnCode(ftpReturn);
            pack.setGridFTPVersion(gftpVersion) ;

            pack.setComponentCode(GFTPMonitorPacket.COMPONENT_CODE);
            pack.setComponentVersion(GFTPMonitorPacket.VERSION_CODE);
            pack.setHostIP(InetAddress.getLocalHost());
            pack.setDateTime(new Date());

            pack.sendPacketToMultiple(socket, addressArray, port);
        }
        catch (IOException ioe) {
            log.error("Couldn't send packet because of IOexception: "+ ioe.getMessage());
        }
    }

    /*Function to send a pre-created packet:*/
    public void sendPacket(UsageMonitorPacket pack) {
        try {
            pack.sendPacketToMultiple(socket, addressArray, port);
        }
        catch (IOException ioe) {
            log.error("Can't send packet because of IOexception in sendPacket()." + ioe.getMessage());
        }
    }
    

    public void shutDown() {
        socket.close();
    }

    private void sendSomeTestPackets() {
        IPTimeMonitorPacket outgoing = new IPTimeMonitorPacket();
        Date now, startDate, endDate;
        Calendar calendar = Calendar.getInstance();

        now = new Date();
        //These are just random dates to test that they come out right on the other end
        calendar.set(1999, 12, 31);
        startDate = calendar.getTime();
        calendar.set(2000, 1, 1);
        endDate = calendar.getTime();


        try {
            //packet with just codes, time, and IP:
            outgoing.setDateTime(now);
            outgoing.setHostIP(InetAddress.getLocalHost());
            outgoing.setComponentCode((short)69);
            outgoing.setComponentVersion((short)42);
            sendPacket(outgoing);
            
            //full-fledged GFTP packet:
            sendPacket(GFTPMonitorPacket.STOR_CODE,
                          startDate, endDate, (long)65535,
                          (long)7, (long)3, (long)32000, (long)64000,
                          (long)227, "Version1");
        }
        catch (UnknownHostException uhe) {
            log.error("Unknown host exception: localhost!");
        }

    }

    private boolean readPropertiesFile(String propertiesFileName) {
        Properties props;
        InputStream propsIn;
        String[] hostNames;
        int i, usableAddresses;

        try {
            props = new Properties();
            propsIn = ExampleGFTPSender.class.getResourceAsStream(propertiesFileName);

            props.load(propsIn);
            port = Integer.parseInt(props.getProperty("listening-port"));
                
            /*If multiple addresses are listed (comma-separated) in the
              properties file, we get back the whole list as one
              string... split it and store all the addresses in an array.*/
            hostNames = props.getProperty("receiver-ip").split(",");

        } catch(IOException e) {
            log.fatal("Can't read file "+propertiesFileName);
            return false;
        } 

        usableAddresses = 0;
        addressArray = new InetAddress[hostNames.length];
        for (i =0; i< hostNames.length; i++) {
            try {
                addressArray[i] = InetAddress.getByName(hostNames[i]);
                usableAddresses ++;
            } catch (UnknownHostException uhe) {
                log.error("Unknown host: "+uhe.getMessage());
                addressArray[i] = null;
            }
        }
        if (usableAddresses == 0) {
            log.fatal("None of the destination hosts specified in the properties file can be resolved.");
            return false;
        }

        log.info("Sender ready.  Will send packets to " + usableAddresses + " hosts on port " + port);
        for (i=0; i<hostNames.length; i++)
            if (addressArray[i] != null)
                log.info("Destination host: " + addressArray[i]);
        return true;
    }


    //Try to get inet address, port from command line
    public boolean readCommandLine(String[] args) {
        if (args.length != 2)
            return false;
        try {
            addressArray = new InetAddress[1];
            addressArray[0] = InetAddress.getByName(args[0]);
            port = Integer.parseInt(args[1]);
        }
        catch (UnknownHostException uhe) {
            log.fatal("Unknown host: "+args[0]);
            return false;
        }
        log.info("Sender ready.  Will send packets to "+addressArray[0] +" on port "+port);
        return true;
    }

    public static void main(String[] args) {
        ExampleGFTPSender sender;
        boolean success;

        /*First try to get port, address from command line; failing that, read
          them from properties file.*/

        try {
            sender = new ExampleGFTPSender();
            success = sender.readCommandLine(args);
            if (!success)
                success = sender.readPropertiesFile("/udpUsage.properties");
            if (!success) {
                log.fatal("You must specify the address and port to send to, either as arguments on the command line, or in the properties file.");
                return;
            }

            sender.sendSomeTestPackets();
        }
        catch (SocketException se) {
            log.fatal("Can't open socket for sending.");
        }
       
    }
}

