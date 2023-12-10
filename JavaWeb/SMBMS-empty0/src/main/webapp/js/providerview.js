var backBtn = null;

$(function () {
    backBtn = $("#back");

    $.ajax({
        type: "GET",//请求类型
        url: path + "/getProviderInfo",//请求的url
        data: {id: $("#id").val()},//请求参数
        dataType: "json",//ajax接口（请求url）返回的数据类型
        success: function (data) {//data：返回数据（json对象）
            if (data != null) {
                $("#proCode").attr("value", data.proCode);
                $("#proName").attr("value", data.proName);
                $("#proContact").attr("value", data.proContact);
                $("#proPhone").attr("value", data.proPhone);
                $("#proAddress").attr("value", data.proAddress);
                $("#proFax").attr("value", data.proFax);
                $("#proDesc").attr("value", data.proDesc);
            }
        },
        error: function (data) {//当访问时候，404，500 等非200的错误状态码
            validateTip($("#proDesc").next(), {"color": "red"}, imgNo + " 获取供应商信息error", false);
        }
    });

    backBtn.on("click", function () {
        //alert("view : "+referer);
        if (referer != undefined
            && null != referer
            && "" != referer
            && "null" != referer
            && referer.length > 4) {
            window.location.href = referer;
        } else {
            history.back(-1);
        }
    });
});