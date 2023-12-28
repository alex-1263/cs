package com.ljx.susheguanli.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.List;

public class Adapter_del extends BaseAdapter {
    Context context;
    List<DormitoryBean> mData;
    LayoutInflater inflater;
    public Adapter_del(Context context, List<DormitoryBean> mData) {
        this.context = context;
        this.mData = mData;
        inflater = LayoutInflater.from(context);
    }
    @Override
    public int getCount() {
        return mData.size();
    }

    @Override
    public Object getItem(int position) {
        return mData.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;
        if (convertView == null) {
            convertView = inflater.inflate(R.layout.item_dormitory_del, parent, false);
            holder = new ViewHolder(convertView);
            convertView.setTag(holder);
        } else {
            holder = (ViewHolder) convertView.getTag();
        }
        DormitoryBean bean=mData.get(position);
        holder.TvNumber.setText("宿舍号:"+bean.getNumber());
        holder.TvName.setText("入住人:"+bean.getName());
        holder.TvMuch.setText("类别:"+bean.getMuch());
        holder.TvSex.setText("人数:"+bean.getSex());
        holder.TvTime.setText("入住时间:"+bean.getTime());
        holder.TvAddress.setText("楼层:"+bean.getAddress());
        holder.TvDes.setText("备注:"+bean.getDes());
        return convertView;
    }
    class ViewHolder {
        TextView TvNumber,TvName, TvMuch, TvSex, TvTime,TvAddress,TvDes;

        public ViewHolder(View view) {
            TvNumber= view.findViewById(R.id.tv_number);
            TvName = view.findViewById(R.id.tv_name);
            TvMuch = view.findViewById(R.id.tv_much);
            TvSex = view.findViewById(R.id.tv_sex);
            TvTime = view.findViewById(R.id.tv_time);
            TvAddress = view.findViewById(R.id.tv_address);
            TvDes = view.findViewById(R.id.tv_des);

        }
    }
}
