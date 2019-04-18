import java.util.stream.IntStream;
import static java.lang.Math.abs;
import static java.lang.Math.pow;

abstract class Hashing extends proc {

    static int h1(String data) {
        long code = 0;
        char[] a = data.toCharArray();
        for(int j = 0;j < data.length(); j++)
            code += IntStream.range(j, data.length()).mapToLong(i -> (long) a[i]).sum() + pow(a[j],j);
        return abs((int)code);
    }

    static int h2(String data) {
        long code = 0;
        char[] a = data.toCharArray();
        for(int i=0; i<data.length();i++)
            code +=  a[i]*pow(31, (data.length() - 1 - i));
        return abs((int)code);
    }

    static int h3(String data) {
        long code = 0;
        char[] a = data.toCharArray();
        for(int i=0; i<data.length();i++)
            code +=  a[i]*(data.length() + 1024 + 2 * i);
        return abs((int)code);
    }

}
