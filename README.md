# Algorithm

begin
    declare students as vector of student

    // step 1: load students from csv file
    call loadStudentsFromCSV("students.csv", students)

    do
        display menu
        input user choice
        
        switch user choice:
            case 0:
                display "Goodbye!"
                break
            case 1:
                call printAllStudentNames(students)
            case 2:
                call printAllStudentData(students)
            case 3:
                call findStudent(students)
            default:
                display "Invalid option, try again!"
        end switch
    while user choice != 0

end

function loadStudentsFromCSV(filename, students)
    open filename
    skip header line
    
    while not end of file
        read line
        parse line to extract student details (first name, last name, address, etc.)
        create a new student object with parsed details
        add student object to students vector
    end while

    display "Loaded X students from X.csv"
end function

function printAllStudentNames(students)
    display "All student names:"
    for each student in students
        display student.getLastFirst()
    end for
end function

function printAllStudentData(students)
    display "All student data:"
    for each student in students
        call student.printStudent()
    end for
end function

function findStudent(students)
    display "Enter the student's name (Last, First):"
    input searchName
    
    set found = false
    for each student in students
        if student.getLastFirst() == searchName then
            call student.printStudent()
            set found = true
            break
        end if
    end for
    
    if not found then
        display "Student not found."
    end if
end function

