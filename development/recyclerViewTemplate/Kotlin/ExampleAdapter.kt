// package com.example.recyclerviewproject -- add the package name according your project structure

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Filter
import android.widget.Filterable
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

import java.util.ArrayList

class ExampleAdapter internal constructor(exampleList: ArrayList<ExampleItem>) : RecyclerView.Adapter<ExampleAdapter.ExampleViewHolder>(), Filterable {
    private val mExampleList: MutableList<ExampleItem>

    class ExampleViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        var mImageView: ImageView = itemView.findViewById(R.id.imageView)
        var mTextView1: TextView = itemView.findViewById(R.id.textView1)
        var mTextView2: TextView = itemView.findViewById(R.id.textView2)

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ExampleViewHolder {
        val v = LayoutInflater.from(parent.context).inflate(R.layout.exampleitem, parent, false)
        return ExampleViewHolder(v)
    }

    override fun onBindViewHolder(holder: ExampleViewHolder, position: Int) {
        val currentItem = mExampleList[position]
        holder.mImageView.setImageResource(currentItem.getmImageResource())
        holder.mTextView1.text = currentItem.getmText1()
        holder.mTextView2.text = currentItem.getmText2()
    }

    override fun getItemCount(): Int {
        return mExampleList.size
    }


}
