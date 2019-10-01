// package com.example.recyclerviewproject -- add the package name according to your project structure

import android.os.Bundle
import android.view.Menu
import android.view.inputmethod.EditorInfo
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.SearchView
import androidx.recyclerview.widget.ItemTouchHelper
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import java.util.*

class MainActivity : AppCompatActivity() {

    private var mRecyclerView: RecyclerView? = null
    private var mAdapter: ExampleAdapter? = null
    private var mLayoutManager: RecyclerView.LayoutManager? = null
    internal var exampleList = ArrayList<ExampleItem>()

    internal var itemTouchHelperCallback: ItemTouchHelper.SimpleCallback = object : ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.RIGHT or ItemTouchHelper.LEFT) {
        override fun onMove(recyclerView: RecyclerView, viewHolder: RecyclerView.ViewHolder, target: RecyclerView.ViewHolder): Boolean {
            return false
        }

        override fun onSwiped(viewHolder: RecyclerView.ViewHolder, direction: Int) {
            //            viewHolder.getAdapterPosition()
            //            exampleList.remove(direction);
            //            notifyItemRemoved()
            //            mAdapter.removeAt(direction);
            mRecyclerView!!.layoutManager = mLayoutManager
            mRecyclerView!!.adapter = mAdapter
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        exampleList.add(ExampleItem(R.drawable.ic_android_black_24dp, "Line 1", "Line 2"))
        exampleList.add(ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 3", "Line 4"))
        exampleList.add(ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 5", "Line 6"))
        exampleList.add(ExampleItem(R.drawable.ic_android_black_24dp, "Line 7", "Line 8"))
        exampleList.add(ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 9", "Line 10"))
        exampleList.add(ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 11", "Line 12"))
        exampleList.add(ExampleItem(R.drawable.ic_android_black_24dp, "Line 13", "Line 2"))
        exampleList.add(ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 15", "Line 14"))
        exampleList.add(ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 17", "Line 16"))
        exampleList.add(ExampleItem(R.drawable.ic_android_black_24dp, "Line 19", "Line 18"))
        exampleList.add(ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 21", "Line 20"))
        exampleList.add(ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 23", "Line 22"))
        exampleList.add(ExampleItem(R.drawable.ic_android_black_24dp, "Line 25", "Line 24"))
        exampleList.add(ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 27", "Line 26"))
        exampleList.add(ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 29", "Line 30"))
        mRecyclerView = findViewById(R.id.recyclerView)
        mRecyclerView!!.setHasFixedSize(true)
        mLayoutManager = LinearLayoutManager(this)
        ItemTouchHelper(itemTouchHelperCallback).attachToRecyclerView(mRecyclerView)
        mAdapter = ExampleAdapter(exampleList)
        mRecyclerView!!.layoutManager = mLayoutManager
        mRecyclerView!!.adapter = mAdapter
    }

}
