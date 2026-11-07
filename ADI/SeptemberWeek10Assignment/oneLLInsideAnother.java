public class oneLLInsideAnother{
    static class node{
        int data;
        node next;

        node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static boolean find(node head1 , node head2) {
        node temp1 = head1;
        node temp2 = head2;


        while(temp1 != null && temp2 != null) {
            if(temp1.data == temp2.data) {
                temp1 = temp1.next;
                temp2 = temp2.next;
            }

            else {
                temp1 = head1;
                if(temp1.data == temp2.data)continue;
                temp2 = temp2.next;
            }
        }

        if(temp1 == null) return true;
        return false;

    }

    public static void printList(node head) {
        node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {

        node head1 = new node(1);
        head1.next = new node(2);
        head1.next.next = new node(3);
        head1.next.next.next = new node(4);
      

        node head2 = new node(1);
        head2.next = new node(2);
        head2.next.next = new node(2);
        head2.next.next.next = new node(1);
        head2.next.next.next.next = new node(2);
        head2.next.next.next.next.next = new node(3);

        printList(head1);
        printList(head2);
        
        boolean ans = find(head1 , head2);

        System.out.println(ans);

    }
}
