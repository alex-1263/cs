package com.edu.servlet.user;

import com.edu.service.bill.BillServiceImpl;
import com.edu.service.provider.ProviderServiceImpl;
import com.edu.service.role.RoleServiceImpl;
import com.edu.service.user.UserServiceImpl;
import com.edu.tools.Constants;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@Controller

public class LogoutServlet {
    @Autowired
    UserServiceImpl userService;
    @Autowired
    RoleServiceImpl roleService;
    @Autowired
    ProviderServiceImpl providerService;
    @Autowired
    BillServiceImpl billService;

    @RequestMapping(value = "/logout.do", method = {RequestMethod.POST, RequestMethod.GET})
    public String doPost(HttpServletRequest request, HttpServletResponse response) {
        //清除session
        request.getSession().removeAttribute(Constants.USER_SESSION);
        return "/login";
    }


}
