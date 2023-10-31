import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ScoreManagementSystem extends JFrame implements ActionListener {
    // 存储成绩信息的文件路径
    private static final String SCORE_FILE_PATH = "scores.csv";

    // 成绩类
    public static class Score {
        private String studentName;
        private int score;

        public Score(String studentName, int score) {
            this.studentName = studentName;
            this.score = score;
        }

        public String getStudentName() {
            return studentName;
        }

        public int getScore() {
            return score;
        }

        public void setStudentName(String studentName) {
            this.studentName = studentName;
        }

        public void setScore(int score) {
            this.score = score;
        }

        @Override
        public String toString() {
            return String.format("%s,%d", studentName, score);
        }
    }

    // 成绩表格模型
    private DefaultTableModel scoreTableModel;

    // 成绩列表
    private List<Score> scores;

    // 成绩表格
    private JTable scoreTable;

    // 操作面板
    private JPanel controlPanel;

    // 添加按钮
    private JButton addButton;

    // 删除按钮
    private JButton deleteButton;

    // 保存按钮
    private JButton saveButton;

    // 构造函数
    public ScoreManagementSystem() {
        super("成绩管理系统");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);
        setLocationRelativeTo(null);

        // 初始化成绩列表
        scores = readScores();

        // 初始化成绩表格模型
        scoreTableModel = new DefaultTableModel(new String[]{"学生姓名", "成绩"}, 0);
        for (Score score : scores) {
            scoreTableModel.addRow(new String[]{score.getStudentName(), Integer.toString(score.getScore())});
        }

        // 初始化成绩表格
        scoreTable = new JTable(scoreTableModel);
        JScrollPane scrollPane = new JScrollPane(scoreTable);
        add(scrollPane, BorderLayout.CENTER);

        // 初始化操作面板
        controlPanel = new JPanel();
        addButton = new JButton("添加");
        addButton.addActionListener(this);
        deleteButton = new JButton("删除");
        deleteButton.addActionListener(this);
        saveButton = new JButton("保存");
        saveButton.addActionListener(this);
        controlPanel.add(addButton);
        controlPanel.add(deleteButton);
        controlPanel.add(saveButton);
        add(controlPanel, BorderLayout.SOUTH);
    }

    // 读取成绩信息
    private List<Score> readScores() {
        List<Score> scores = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(SCORE_FILE_PATH))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] fields = line.split(",");
                String studentName = fields[0];
                int score = Integer.parseInt(fields[1]);
                scores.add(new Score(studentName, score));
            }
        } catch (IOException e)
        {
            e.printStackTrace();
        }
        return scores;
    }
    // 保存成绩信息
    private void saveScores() {
        try (FileWriter writer = new FileWriter(SCORE_FILE_PATH)) {
            for (Score score : scores) {
                writer.write(score.toString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 添加成绩
    private void addScore() {
        String studentName = JOptionPane.showInputDialog(this, "请输入学生姓名：");
        if (studentName != null && !studentName.isEmpty()) {
            String scoreStr = JOptionPane.showInputDialog(this, "请输入成绩：");
            if (scoreStr != null && !scoreStr.isEmpty()) {
                try {
                    int score = Integer.parseInt(scoreStr);
                    scores.add(new Score(studentName, score));
                    scoreTableModel.addRow(new String[]{studentName, Integer.toString(score)});
                } catch (NumberFormatException e) {
                    JOptionPane.showMessageDialog(this, "成绩必须是数字！", "错误", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
    }

    // 删除成绩
    private void deleteScore() {
        int[] selectedRows = scoreTable.getSelectedRows();
        if (selectedRows.length > 0) {
            int option = JOptionPane.showConfirmDialog(this, "确定删除选中的成绩吗？", "删除成绩", JOptionPane.YES_NO_OPTION);
            if (option == JOptionPane.YES_OPTION) {
                for (int i = selectedRows.length - 1; i >= 0; i--) {
                    scores.remove(selectedRows[i]);
                    scoreTableModel.removeRow(selectedRows[i]);
                }
            }
        } else {
            JOptionPane.showMessageDialog(this, "请先选择要删除的成绩！", "提示", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    // 保存成绩
    private void saveScore() {
        saveScores();
        JOptionPane.showMessageDialog(this, "保存成功！", "提示", JOptionPane.INFORMATION_MESSAGE);
    }

    // 监听按钮点击事件
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == addButton) {
            addScore();
        } else if (e.getSource() == deleteButton) {
            deleteScore();
        } else if (e.getSource() == saveButton) {
            saveScore();
        }
    }

    // 主函数
    public static void main(String[] args) {
        ScoreManagementSystem system = new ScoreManagementSystem();
        system.setVisible(true);
    }
}