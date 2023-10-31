package com.blog.servlet;

import com.blog.dao.UserDao;
import com.blog.dao.impl.UserDaoImpl;
import com.blog.entity.User;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;

@WebServlet("/LoginServlet")
public class LoginServlet  extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws SecurityException, IOException{
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        String username=request.getParameter("username");  //读取用户名
        String password=request.getParameter("password");
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        UserDao userDao= new UserDaoImpl() {
            @Override
            public int addUser(String username, String password, String sex, String email, Date time) {
                return 0;
            }
        };
        boolean b=userDao.getUser(user);
        if(b){
            request.getSession().setAttribute("username",username);
            Cookie cookie=new Cookie("username",username);
            //session.setAttribute("username", username);
            cookie.setPath("/");
            response.addCookie(cookie);
            //response.sendRedirect(request.getContextPath()+"/jsp/index.jsp");
            response.sendRedirect("index.jsp");
        }
        else{
            response.getWriter().print("<script type='text/javascript'>alert('登录失败')</script>");
            response.setHeader("refresh", "2;url=login.jsp");
        }
    }
}
