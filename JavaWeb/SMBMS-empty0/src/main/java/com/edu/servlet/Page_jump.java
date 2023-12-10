package com.edu.servlet;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import javax.servlet.http.HttpServletRequest;

@Controller
public class Page_jump {
    //表示方法与请求URL的映射，这里映射/index请求
    @RequestMapping("/")
    public String redirectToDefaultPage() {
        return "login";
    }

//    @RequestMapping("/login")
    public String redirectToframePage() {
        return "frame";
    }

//    @RequestMapping("/queryBill")
//    public String redirectToBillPage() {
//        return "billlist";
//    }
//    @RequestMapping("/queryProvider")
//    public String redirectToProPage() {
//        return "providerlist";
//    }
//    @RequestMapping("/queryUser")
//    public String redirectToUserPage() {
//        return "userlist";
//    }

    @RequestMapping(value = "/billAddPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String billadd() {
        return "billadd";
    }

    @RequestMapping(value = "/billModifyPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String billModify(HttpServletRequest request, String billId) {
        request.setAttribute("billId", billId);
        return "billmodify";
    }

    @RequestMapping(value = "/billViewPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String billViewPage(HttpServletRequest request, String billId) {
        request.setAttribute("billId", billId);
        return "billview";
    }

    @RequestMapping(value = "/pwdmodifyPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String pwdmodify() {
        return "pwdmodify";
    }

    @RequestMapping(value = "/providerAddPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String provideradd() {
        return "provideradd";
    }

    @RequestMapping(value = "/providerModifyPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String providerModify(HttpServletRequest request, String proid) {
        request.setAttribute("proid",proid);
        return "providermodify";
    }

    @RequestMapping(value = "/providerViewPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String providerView(HttpServletRequest request, String proid) {
        request.setAttribute("proid",proid);
        return "providerview";
    }

    @RequestMapping(value = "/useraddPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String useradd() {
        return "useradd";
    }

    @RequestMapping(value = "/userModifyPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String userModify(HttpServletRequest request, String uid) {
        request.setAttribute("uid",uid);
        return "usermodify";
    }

    @RequestMapping(value = "/userViewPage", method = {RequestMethod.POST, RequestMethod.GET})
    public String userView(HttpServletRequest request, String uid) {
        request.setAttribute("uid",uid);
        return "userview";
    }
}
