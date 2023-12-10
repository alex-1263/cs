package com.edu.tools;

import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.Date;

public class ConvertUtil {
    public static void sendJsonnMsg(HttpServletResponse response, String message) throws IOException {
        response.setContentType("application/json");
        PrintWriter printWriter = response.getWriter();
        printWriter.write(message);
        printWriter.flush();
    }

    /**
     * 根据生日计算年龄
     *
     * @param birthDate
     * @return
     */
    public static int getAge(Date birthDate) {
        Calendar cal = Calendar.getInstance();

        if (cal.before(birthDate)) {
            throw new IllegalArgumentException("The birth date is after the current date.");
        }

        int yearNow = cal.get(Calendar.YEAR);
        int monthNow = cal.get(Calendar.MONTH) + 1;
        int dayOfMonthNow = cal.get(Calendar.DAY_OF_MONTH);

        cal.setTime(birthDate);
        int yearBirth = cal.get(Calendar.YEAR);
        int monthBirth = cal.get(Calendar.MONTH) + 1;
        int dayOfMonthBirth = cal.get(Calendar.DAY_OF_MONTH);

        int age = yearNow - yearBirth;

        if (monthNow < monthBirth || (monthNow == monthBirth && dayOfMonthNow < dayOfMonthBirth)) {
            age--;
        }

        return age;
    }
}
