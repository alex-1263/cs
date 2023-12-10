package com.edu.servlet;

import com.alibaba.fastjson.JSONArray;
import com.edu.pojo.Bill;
import com.edu.pojo.Provider;
import com.edu.pojo.User;
import com.edu.service.bill.BillService;
import com.edu.service.provider.ProviderService;
import com.edu.service.provider.ProviderServiceImpl;
import com.edu.tools.Constants;
import com.edu.tools.ConvertUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.List;

@Controller
public class BillController {

    @Autowired
    BillService billService;
    @Autowired
    ProviderService providerService;

    @RequestMapping("/queryBill")
    public String redirectToBillPage(HttpServletRequest request, String queryProductName, Integer queryProviderId, Integer queryIsPayment) {
        List<Bill> billList = billService.queryBill(queryProductName, queryProviderId, queryIsPayment);
        List<Provider> providerList = providerService.queryProvider();
        request.setAttribute("billList", billList);
        request.setAttribute("providerList", providerList);
        request.setAttribute("queryProductName", queryProductName);
        request.setAttribute("queryProviderId", queryProviderId);
        request.setAttribute("queryIsPayment", queryIsPayment);
        return "billlist";
    }

    @RequestMapping("/getProviderlist")
    public void getProviderList(HttpServletResponse response) throws IOException {
        List<Provider> providerList = providerService.queryProvider();

        response.setContentType("application/json");
        PrintWriter printWriter = response.getWriter();
        printWriter.write(JSONArray.toJSONString(providerList));
        printWriter.flush();
    }

    @RequestMapping("addBill")
//        public String addBill(HttpServletResponse response, HttpServletRequest request,String billCode,String productName,String productUnit,Double productCount,Double totalPrice,Integer providerId,Integer isPayment) throws IOException, ServletException {
    public String addBill(HttpServletResponse response, HttpServletRequest request,Bill bill) throws IOException, ServletException {

//        Bill bill = new Bill();
//        bill.setBillCode(billCode);
//        bill.setProductName(productName);
//        bill.setProductUnit(productUnit);
//        bill.setProductCount(productCount);
//        bill.setTotalPrice(totalPrice);
//        bill.setProviderId(providerId);
//        bill.setIsPayment(isPayment);

        User user = (User) request.getSession().getAttribute(Constants.USER_SESSION);
        if (user != null) {
            bill.setCreatedBy(user.getId());
        }
//        bill.setCreatedBy(user.getId());
        bill.setCreationDate(new Date());

        int result = billService.addBill(bill);
        if (result > 0) {
            request.getRequestDispatcher("/queryBill").forward(request, response);
            return null;
//              return "redirect:/queryBill";
//              return null;
//              return "billlist";
        }
        return "billadd";
    }
    @RequestMapping("/getBillById")
    public void getBillById(HttpServletResponse response,String id) throws IOException {
        Bill bill = billService.getBillById(id);
        String jsonStr=JSONArray.toJSONString(bill);
        ConvertUtil.sendJsonnMsg(response,jsonStr);
    }


    /**
     * 供应商管理
     *
     * @param request
     * @return
     */
    @RequestMapping("/queryProvider")
    public String supplier(HttpServletRequest request) {
        List<Provider> providerList = providerService.suppliermanage();
        request.setAttribute("providerList", providerList);
        return "providerlist";
    }
    @RequestMapping("/billModify")
    public String modifyBill(HttpServletRequest request,Bill bill){
        User loginedUser = (User) request.getSession().getAttribute(Constants.USER_SESSION);
        bill.setModifyBy(loginedUser.getId());
        bill.setModifyDate(new Date());
        int result=billService.modifyBill(bill);
        if (result > 0){
            return "redirevt:/queryBill";

        }
        return "billmodify";
    }
}
