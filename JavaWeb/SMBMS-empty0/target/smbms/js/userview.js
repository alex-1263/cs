var backBtn = null;

$(function () {
    backBtn = $("#back");
    userRole = $("#userRole");

    $.ajax({
        type: "GET",//请求类型
        url: path + "/getRoleList",//请求的url
        dataType: "json",//ajax接口（请求url）返回的数据类型
        success: function (data) {//data：返回数据（json对象）
            if (data != null) {
                //获取到角色列表后，加载到select控件中
                userRole.html("");
                var options = "<option value=\"0\">请选择</option>";
                for (var i = 0; i < data.length; i++) {
                    options += "<option value=\"" + data[i].id + "\" >" + data[i].roleName + "</option>";
                }
                userRole.html(options);

                //根据用户id，获取当前用户的信息
                $.ajax({
                    type: "GET",//请求类型
                    url: path + "/getUserInfo",//请求的url
                    data: {id: $("#uid").val()},//请求参数
                    dataType: "json",//ajax接口（请求url）返回的数据类型
                    success: function (data) {//data：返回数据（json对象）
                        if (data != null) {
                            $("#userName").attr("value", data.userName);
                            $("#gender").attr("value", data.gender);
                            const date = new Date(data.birthday);
                            $("#birthday").attr("value", date.getFullYear() + "-" + date.getMonth() + "-" + date.getDay());
                            $("#phone").attr("value", data.phone);
                            $("#address").attr("value", data.address);
                            $("#userRole").val(data.userRole);
                        }
                    },
                    error: function (data) {//当访问时候，404，500 等非200的错误状态码
                        validateTip(userRole.next(), {"color": "red"}, imgNo + " 获取用户信息error", false);
                    }
                });
            }
        },
        error: function (data) {//当访问时候，404，500 等非200的错误状态码
            validateTip(userRole.next(), {"color": "red"}, imgNo + " 获取用户角色列表error", false);
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