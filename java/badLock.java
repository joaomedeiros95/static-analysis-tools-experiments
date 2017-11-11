import java.util.concurrent.locks.ReentrantLock;

public class badLock {
	static private final ReentrantLock BAD_REENTRANT_LOCK = new ReentrantLock();

    public static void main(String[] args) {
        BAD_REENTRANT_LOCK.lock();
        
        int intBadNumber = 0;
        intBadNumber++;
        
        System.out.println(intBadNumber);
        
        /* FLAW: lock is not unlocked */
    }

}
    