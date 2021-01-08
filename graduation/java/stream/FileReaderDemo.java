import java.io.*;
public class FileReaderDemo
{
    public static void main(String[] args) throws IOException
    {
        FileReader in = null;
        FileWriter out = null;
        try
        {
            in = new FileReader("/etc/hosts");
            out = new FileWriter("hosts_FileWriter");

            int c;
            // copy the file content in bytes
            while ((c = in.read()) != -1)
            {
                out.write(c);
            }
            System.out.println("File is copied successful!");
        }finally {
            if (in != null){
                in.close();
            }
            if (out != null){
                out.close();
            }
        }
    }
}
