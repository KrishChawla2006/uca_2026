: << 'COMMENT'
30. Practice with awk
You are given a data file named employees.txt which contains information about a small company's engineering team. The fields are separated by a comma (,) and represent: Name, Department, HourlyWage, HoursWorked

Create the data file using the text below:

Alice,Engineering,50,40
Bob,Marketing,35,38
Charlie,Engineering,60,45
David,HR,30,40
Eva,Engineering,55,35
Task1: Basic Field Extraction
Print only the names and departments of all employees. The output should look like this:

Alice Engineering
Bob Marketing
...
Task2: Filtering by Row (Pattern Matching)
Filter the dataset to only display employees who work in the Engineering department. Print their entire record. The output should look like this:

Alice,Engineering,50,40
Charlie,Engineering,60,45
Eva,Engineering,55,35
Task3: Basic Arithmetic (Calculating Total Pay)
Write an awk script to calculate the gross pay for each employee (HourlyWage * HoursWorked). Print the employee's name followed by their calculated pay. Output should look like this

Alice gross pay: $2000
Bob gross pay: $1330
Charlie gross pay: $2700
David gross pay: $1200
Eva gross pay: $1925
Task4: Using Built-in Variables (NR and NF)
Print every line of the file, prefixed by its line number (Record Number) and the total number of fields in that line. Output should look like this

1 (4 fields): Alice,Engineering,50,40
2 (4 fields): Bob,Marketing,35,38
3 (4 fields): Charlie,Engineering,60,45
4 (4 fields): David,HR,30,40
5 (4 fields): Eva,Engineering,55,35
Task 5: The Grand Finale (BEGIN, END, and Conditionals)
Write a complete awk command that:

Calculates the total payroll cost for the Engineering department only.
Prints the final total at the end of the execution.
Output should look like this

Total Engineering Payroll: $6625
Please create a shell script and submit your solution by providing a GitHub file link.
COMMENT



#!/bin/bash
echo "========== Task 1 =========="
awk -F',' '{print $1, $2}' employees.txt

echo
echo "========== Task 2 =========="
awk -F',' '$2=="Engineering"' employees.txt

echo
echo "========== Task 3 =========="
awk -F',' '{print $1 " gross pay: $" $3*$4}' employees.txt

echo
echo "========== Task 4 =========="
awk -F',' '{print NR " (" NF " fields): " $0}' employees.txt

echo
echo "========== Task 5 =========="
awk -F',' '
BEGIN {
    total = 0
}
$2 == "Engineering" {
    total += $3 * $4
}
END {
    print "Total Engineering Payroll: $" total
}
' employees.txt
