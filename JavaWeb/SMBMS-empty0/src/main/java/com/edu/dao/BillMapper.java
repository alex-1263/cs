package com.edu.dao;

import com.edu.pojo.Bill;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface BillMapper {
    /**
     * 查询所有订单
     * @return
     */
    public List<Bill> queryBill(@Param("productName") String productName, @Param("providerId") Integer providerId, @Param("isPayment") Integer isPayment);

    /**
     * 根据前端传递的参数执行订单添加
     * @param bill
     * @return
     */
    public int addBill(Bill bill);

    public Bill getBillById(String id);
    public int modifyBill(Bill bill);
}
