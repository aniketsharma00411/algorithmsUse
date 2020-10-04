
import java.util.LinkedList;

public class valid_parentheses {


    /**
     * Determine if the input string is valid.
     * An input string is valid if:
     * Open brackets must be closed by the same type of brackets.
     * Open brackets must be closed in the correct order.*
     * @param s String
     */
    boolean isValid(String s) {
        if(s.length() % 2 != 0)
            return false;

        LinkedList<Character> stack = new LinkedList<>();
        
        char [] arrayChar = s.toCharArray();
        
        for (char c : arrayChar) {
            
            if(c == '(' || c == '[' || c == '{' ){
                stack.push(c);
            }else if(c == ')' && !stack.isEmpty() && stack.peek() == '(' ){
                stack.pop();
            }else if(c == ']' && !stack.isEmpty() && stack.peek() == '[' ){
                stack.pop();
            }else if(c == '}' && !stack.isEmpty() && stack.peek() == '{' ){
                stack.pop();
            }
            
        }
        
        return stack.isEmpty();
    }

}