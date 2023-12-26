package com.edu.servlet.user;

import com.edu.pojo.User;
import com.edu.service.bill.BillServiceImpl;
import com.edu.service.provider.ProviderServiceImpl;
import com.edu.service.role.RoleServiceImpl;
import com.edu.service.user.UserServiceImpl;
import com.edu.tools.Constants;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@Controller
public class LoginServlet {
    @Autowired
    UserServiceImpl userService;
    @Autowired
    RoleServiceImpl roleService;
    @Autowired
    ProviderServiceImpl providerService;
    @Autowired
    BillServiceImpl billService;

    @RequestMapping(value = "/login.do", method = {RequestMethod.POST, RequestMethod.GET})
    public String doPost(HttpServletRequest request, HttpServletResponse response, Model model) {
        System.out.println("login ============ ");
        //获取用户名和密码
        String userCode = request.getParameter("userCode");
        String userPassword = request.getParameter("userPassword");
        System.out.println(userCode + " " + userPassword);
        //调用service方法，进行用户匹配
        User user = userService.login(userCode, userPassword);
        System.out.println(user);
        if (null != user) {//登录成功
            //放入session
            request.getSession().setAttribute(Constants.USER_SESSION, user);
            //页面跳转（frame.jsp）
            return "frame";
        } else {
            //页面跳转（login.jsp）带出提示信息--转发
            model.addAttribute("error", "用户名或密码不正确");
            return "login";
            //.forward(request, response);
        }
    }


}
