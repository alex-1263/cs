var backBtn = null;

$(function(){
	backBtn = $("#back");
	billCode = $("#billCode");
	productName = $("#productName");
	productUnit = $("#productUnit");
	productCount = $("#productCount");
	totalPrice = $("#totalPrice");
	providerId = $("#providerId");

	$.ajax({
		type:"GET",//请求类型
		url:path+"/getProviderlist",//请求的url
		dataType:"json",//ajax接口（请求url）返回的数据类型
		success:function(data){//data：返回数据（json对象）
			console.log(data)
			if(data != null){
				var pid = $("#pid").val();
				$("select").html("");//通过标签选择器，得到select标签，适用于页面里只有一个select
				var options = "<option value=\"0\">请选择</option>";
				for(var i = 0; i < data.length; i++){
					if(pid != null && pid != undefined && data[i].id == pid ){
						options += "<option selected=\"selected\" value=\""+data[i].id+"\" >"+data[i].proName+"</option>";
					}else{
						options += "<option value=\""+data[i].id+"\" >"+data[i].proName+"</option>";
					}

				}
				$("select").html(options);

				//再次通过ajax，根据订单id获取订单详细信息
				$.ajax({
					type: "GET",//请求类型
					url: path + "/getBillById",//请求的url
					data: {id: $("#id").val()},//请求参数
					dataType: "json",//ajax接口（请求url）返回的数据类型
					success: function (data) {//data：返回数据（json对象）
						if (data != null) {
							$("#billCode").attr("value", data.billCode);
							$("#productName").attr("value", data.productName);
							$("#productUnit").attr("value", data.productUnit);
							$("#productCount").attr("value", data.productCount);
							$("#totalPrice").attr("value", data.totalPrice);
							$("#providerId").val(data.providerId);
							$('input[name="isPayment"][value='+data.isPayment+']').prop('checked', true);
						}
					},
					error: function (data) {//当访问时候，404，500 等非200的错误状态码
						validateTip(userRole.next(), {"color": "red"}, imgNo + " 获取用户信息error", false);
					}
				});
			}
		},
		error:function(data){//当访问时候，404，500 等非200的错误状态码
			validateTip(providerId.next(),{"color":"red"},imgNo+" 获取供应商列表error",false);
		}
	});

	backBtn.on("click",function(){
		if(referer != undefined 
			&& null != referer 
			&& "" != referer
			&& "null" != referer
			&& referer.length > 4){
		 window.location.href = referer;
		}else{
			history.back(-1);
		}
	});
});