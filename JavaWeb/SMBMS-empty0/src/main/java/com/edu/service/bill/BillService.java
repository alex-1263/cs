package com.edu.service.bill;

import com.edu.pojo.Bill;

import java.util.List;

public interface BillService {
     List<Bill> queryBill(String productName,Integer providerId, Integer isPayment);
     public int addBill(Bill bill);

     public Bill getBillById(String id);
     public int modifyBill(Bill bill);
}
