import java.util.ArrayList;
import java.util.Scanner;

public class StudentManagementSystem {


    public static void main(String[] args) {

        ArrayList<Student> students = new ArrayList<Student>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("请选择操作：");
            System.out.println("1.添加学生信息");
            System.out.println("2.删除学生信息");
            System.out.println("3.修改学生信息");
            System.out.println("4.查询学生信息");
            System.out.println("5.退出程序");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addStudent(students, scanner);
                    break;
                case 2:
                    deleteStudent(students, scanner);
                    break;
                case 3:
                    modifyStudent(students, scanner);
                    break;
                case 4:
                    searchStudent(students, scanner);
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("无效操作，请重新选择。");
                    break;
            }
        }
    }



    public static void addStudent(ArrayList<Student> students, Scanner scanner) {
        System.out.println("请输入学生姓名：");
        String name = scanner.next();
        System.out.println("请输入学生年龄：");
        int age = scanner.nextInt();
        System.out.println("请输入学生性别：");
        String gender = scanner.next();

        Student student = new Student(name, age, gender);
        students.add(student);
        System.out.println("学生信息添加成功。");
    }

    public static void deleteStudent(ArrayList<Student> students, Scanner scanner) {
        System.out.println("请输入要删除的学生姓名：");
        String name = scanner.next();

        boolean isRemoved = false;
        for (int i = 0; i < students.size(); i++) {
            Student student = students.get(i);
            if (student.getName().equals(name)) {
                students.remove(i);
                isRemoved = true;
                System.out.println("学生信息删除成功。");
                break;
            }
        }

        if (!isRemoved) {
            System.out.println("未找到该学生信息。");
        }
    }

    public static void modifyStudent(ArrayList<Student> students, Scanner scanner) {
        System.out.println("请输入要修改的学生姓名：");
        String name = scanner.next();

        boolean isModified = false;
        for (int i = 0; i < students.size(); i++) {
            Student student = students.get(i);
            if (student.getName().equals(name)) {
                System.out.println("请输入修改后的学生年龄：");
                int age = scanner.nextInt();
                System.out.println("请输入修改后的学生性别：");
                String gender = scanner.next();
                student.setAge(age);
                student.setGender(gender);
                isModified = true;
                System.out.println("学生信息修改成功。");
                break;
            }
        }

        if (!isModified) {
            System.out.println("未找到该学生信息。");
        }
    }

    public static void searchStudent(ArrayList<Student> students, Scanner scanner) {
        System.out.println("请输入要查询的学生姓名：");
        String name = scanner.next();

        boolean isFound = false;
        for (int i = 0; i < students.size(); i++) {
            Student student = students.get(i);
            if (student.getName().equals(name)) {
                System.out.println("查询结果：");
                System.out.println("姓名：" + student.getName());
                System.out.println("年龄：" + student.getAge());
                System.out.println("性别：" + student.getGender());
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            System.out.println("未找到该学生信息。");
        }
    }
}
