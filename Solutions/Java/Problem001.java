import java.util.Arrays;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class Problem001 {
    public static boolean resolveProblem001(ArrayList<Integer> array, int k) {
        Set<Integer> fSet = new HashSet<Integer>();

        for(Integer e : array) {
            if(fSet.contains(e)) {
                return true;
            }

            fSet.add(k - e);
        }

        return false;
    }

    public static void test() {
        ArrayList<Integer> test1 = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5, 6, 7));

        assert(resolveProblem001(test1, 13));
        assert(resolveProblem001(test1, 12));
        assert(!resolveProblem001(test1, 14));
        assert(!resolveProblem001(test1, 1));
    
    }
    public static void main(String[] args) {
        test();
    }
}
