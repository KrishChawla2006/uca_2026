public class reverseLL{

    static class node{
        int data;
        node next;
        node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static node reverse(node head) {
        if(head == null || head.next == null) return head;

        node newHead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;

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
        node head = new node(1);
        node temp = head;
        int i = 2;
        while(i <= 5) {
            temp.next = new node(i++);
            temp = temp.next;
        }
        printList(head);
        head = reverse(head);
        printList(head);
    }

}
