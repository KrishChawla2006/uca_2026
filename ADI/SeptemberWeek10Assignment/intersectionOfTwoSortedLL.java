public class intersectionLL{
    static class node{
        int data;
        node next;

        node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static node intersection(node head1 , node head2) {
        node temp1 = head1;
        node temp2 = head2;

        node head = null;
        node temp = null;

        while(temp1 != null && temp2 != null) {
            if(temp1.data == temp2.data) {
                if(head == null) {
                    head = new node(temp1.data);
                    temp = head;
                }
                else{
                    temp.next = new node(temp1.data);
                    temp = temp.next;
                }
                temp1 = temp1.next;
                temp2 = temp2.next;
            }

            else if(temp1.data < temp2.data) {
                temp1 = temp1.next;
            }

            else {
                temp2 = temp2.next;
            }
        }

        temp.next = null;
        return head;

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
        head1.next.next = new node(2);
        head1.next.next.next = new node(3);
        head1.next.next.next.next = new node(4);

        node head2 = new node(2);
        head2.next = new node(2);
        head2.next.next = new node(2);
        head2.next.next.next = new node(4);

        printList(head1);
        printList(head2);
        
        node head = intersection(head1 , head2);

        printList(head);

    }
}
