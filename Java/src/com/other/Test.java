package com.other;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Test{
    public static void main(String[] args) {
        System.out.println("good");
        Test test = new Test();
        try {
            System.out.println(test.getValue("src/com/other/Test.java"));
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public String getValue(String path) throws FileNotFoundException {
        File file = new File(path);
        try {
            FileInputStream fileInputStream = new FileInputStream(file);
            int numRead = 0;
            StringBuffer stringBuffer = new StringBuffer();

            do {
                byte[] buffer = new byte[1024];

                numRead = fileInputStream.read(buffer);
                System.out.println(numRead);
                if (numRead > 0) {
                    stringBuffer.append(new String(buffer));
                }
            } while (numRead != -1);

            fileInputStream.close();
            String s = stringBuffer.toString();
            System.out.println("读取到的字符串为：" + s);
            return stringBuffer.toString();

        } catch (Exception e) {
            e.printStackTrace();
        }
        return "Error";
    }
}