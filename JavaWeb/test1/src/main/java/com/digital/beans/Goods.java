package com.digital.beans;

public class Goods {
        private static Goods goods1;
        private int gid;
        private String code;
        private String name;
        private String type;
        private String pic;
        private int num;
        private String price;
        private String sale;
        private String intro;

        public static Goods getGoods1() {
                return goods1;
        }

        public static void setGoods1(Goods goods1) {
                Goods.goods1 = goods1;
        }

        public int getGid() {
                return gid;
        }

        public void setGid(int gid) {
                this.gid = gid;
        }

        public String getCode() {
                return code;
        }

        public void setCode(String code) {
                this.code = code;
        }

        public String getName() {
                return name;
        }

        public void setName(String name) {
                this.name = name;
        }

        public String getType() {
                return type;
        }

        public void setType(String type) {
                this.type = type;
        }

        public String getPic() {
                return pic;
        }

        public void setPic(String pic) {
                this.pic = pic;
        }

        public int getNum() {
                return num;
        }

        public void setNum(int num) {
                this.num = num;
        }

        public String getPrice() {
                return price;
        }

        public void setPrice(String price) {
                this.price = price;
        }

        public String getSale() {
                return sale;
        }

        public void setSale(String sale) {
                this.sale = sale;
        }

        public String getIntro() {
                return intro;
        }

        public void setIntro(String intro) {
                this.intro = intro;
        }
}
