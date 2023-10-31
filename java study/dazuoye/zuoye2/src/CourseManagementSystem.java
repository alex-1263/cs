import java.io.*;
import java.util.*;

public class CourseManagementSystem {
    // 存储课程信息的文件路径
    private static final String COURSE_FILE_PATH = "courses.txt";

    // 课程类
    public static class Course {
        private String name;
        private String teacher;
        private int credit;

        public Course(String name, String teacher, int credit) {
            this.name = name;
            this.teacher = teacher;
            this.credit = credit;
        }

        public String getName() {
            return name;
        }

        public String getTeacher() {
            return teacher;
        }

        public int getCredit() {
            return credit;
        }

        public void setName(String name) {
            this.name = name;
        }

        public void setTeacher(String teacher) {
            this.teacher = teacher;
        }

        public void setCredit(int credit) {
            this.credit = credit;
        }

        @Override
        public String toString() {
            return String.format("%s,%s,%d", name, teacher, credit);
        }
    }

    // 读取课程信息
    private static List<Course> readCourses() {
        List<Course> courses = new ArrayList<>();
        try (Scanner scanner = new Scanner(new File(COURSE_FILE_PATH))) {
            while (scanner.hasNextLine()) {
                String[] fields = scanner.nextLine().split(",");
                String name = fields[0];
                String teacher = fields[1];
                int credit = Integer.parseInt(fields[2]);
                courses.add(new Course(name, teacher, credit));
            }
        } catch (FileNotFoundException e) {
            // 文件不存在时，返回一个空列表
            return new ArrayList<>();
        }
        return courses;
    }

    // 写入课程信息
    private static void writeCourses(List<Course> courses) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(COURSE_FILE_PATH))) {
            for (Course course : courses) {
                writer.println(course);
            }
        } catch (IOException e) {
            System.out.println("写入文件失败：" + e.getMessage());
        }
    }

    // 添加课程
    private static void addCourse(Scanner scanner, List<Course> courses) {
        System.out.println("请输入课程名称：");
        String name = scanner.nextLine();
        System.out.println("请输入授课教师：");
        String teacher = scanner.nextLine();
        System.out.println("请输入学分：");
        int credit = scanner.nextInt();
        scanner.nextLine(); // 吃掉输入缓冲区的换行符
        courses.add(new Course(name, teacher, credit));
        System.out.println("课程添加成功！");
    }

    // 删除课程
    private static void deleteCourse(Scanner scanner, List<Course> courses) {
        System.out.println("请输入要删除的课程名称：");
        String name = scanner.nextLine();
        Iterator<Course> iterator = courses.iterator();
        boolean found = false;
        while (iterator.hasNext()) {
            Course course = iterator.next();
            if (course.getName().equals(name)) {
                iterator.remove();
                found = true;
            }
        }
        if (found) {
            System.out.println("课程删除成功！");
        } else {
            System.out.println("未找到要删除的课程！");
        }
    }

    // 修改课程
    private static void updateCourse(Scanner scanner, List<Course> courses) {
        System.out.println("请输入要修改的课程名称：");
        String name = scanner.nextLine();
        for (Course course : courses) {
            if (course.getName().equals(name)) {
                System.out.println("请输入新的课程名称（回车跳过）：");
                String newName = scanner.nextLine();
                if (!newName.equals("")) {
                    course.setName(newName);
                }
                System.out.println("请输入新的授课教师（回车跳过）：");
                String newTeacher = scanner.nextLine();
                if (!newTeacher.equals("")) {
                    course.setTeacher(newTeacher);
                }
                System.out.println("请输入新的学分（回车跳过）：");
                String newCreditString = scanner.nextLine();
                if (!newCreditString.equals("")) {
                    int newCredit = Integer.parseInt(newCreditString);
                    course.setCredit(newCredit);
                }
                System.out.println("课程修改成功！");
                return;
            }
        }
        System.out.println("未找到要修改的课程！");
    }

    // 查询课程
    private static void queryCourse(Scanner scanner, List<Course> courses) {
        System.out.println("请输入要查询的课程名称（回车查询所有课程）：");
        String name = scanner.nextLine();
        if (name.equals("")) {
            for (Course course : courses) {
                System.out.println(course);
            }
        } else {
            for (Course course : courses) {
                if (course.getName().equals(name)) {
                    System.out.println(course);
                    return;
                }
            }
            System.out.println("未找到要查询的课程！");
        }
    }

    public static void main(String[] args) {
        List<Course> courses = readCourses();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("请选择操作：");
            System.out.println("1.添加课程");
            System.out.println("2.删除课程");
            System.out.println("3.修改课程");
            System.out.println("4.查询课程");
            System.out.println("5.退出程序");
            int choice = scanner.nextInt();
            scanner.nextLine(); // 吃掉输入缓冲区的换行符
            switch (choice) {
                case 1:
                    addCourse(scanner, courses);
                    break;
                case 2:
                    deleteCourse(scanner, courses);
                    break;
                case 3:
                    updateCourse(scanner, courses);
                    break;
                case 4:
                    queryCourse(scanner, courses);
                    break;
                case 5:
                    writeCourses(courses);
                    System.out.println("程序已退出。");
                    return;
                default:
                    System.out.println("无效的选择，请重新输入。");
            }
        }
    }
}

