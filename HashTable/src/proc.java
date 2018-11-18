import java.util.Objects;
import java.util.ArrayList;
import java.io.File;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

abstract class proc {
    private static ArrayList<String> readTxtFile(String filePath, int num){
        try {
            String encoding="UTF-8";
            File file = new File(filePath);
            if(file.isFile() && file.exists()){
                InputStreamReader read = new InputStreamReader(
                        new FileInputStream(file),encoding);
                ArrayList<String> readList = new ArrayList<String>();
                BufferedReader bufferedReader = new BufferedReader(read);
                String buffer;
                int count = 0;
                while((buffer = bufferedReader.readLine()) != null && !"".equals(buffer)){
                    if(count >= num)
                        break;
                    count++;
                    //System.out.println("String " + count + ": " + buffer);
                    readList.add(buffer);
                }
                System.out.println("String Number: " + count);
                read.close();
                return readList;
            }else{
                System.out.println("File Not Found");
                return null;
            }
        } catch (Exception e) {
            System.out.println("Failed to Read Content");
            e.printStackTrace();
            return null;
        }
    }

    static ArrayList<String> getNameCodes(String filepath, int num)
    {
        ArrayList<String> CodeNames = readTxtFile(filepath, num);
        System.out.println("Array Size: " + Objects.requireNonNull(CodeNames).size()
                + " (Should Match String Number)");
        //System.out.println(CodeNames);
        return CodeNames;
    }

}
