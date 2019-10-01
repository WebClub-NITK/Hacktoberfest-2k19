// package com.example.recyclerviewproject; -- add correct package name here

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.Filter;
import android.widget.Filterable;

import androidx.appcompat.widget.SearchView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private RecyclerView mRecyclerView;
    private ExampleAdapter mAdapter;
    private RecyclerView.LayoutManager mLayoutManager;
    ArrayList<ExampleItem> exampleList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        exampleList.add(new ExampleItem(R.drawable.ic_android_black_24dp, "Line 1", "Line 2"));
        exampleList.add(new ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 3", "Line 4"));
        exampleList.add(new ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 5", "Line 6"));
        exampleList.add(new ExampleItem(R.drawable.ic_android_black_24dp, "Line 7", "Line 8"));
        exampleList.add(new ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 9", "Line 10"));
        exampleList.add(new ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 11", "Line 12"));
        exampleList.add(new ExampleItem(R.drawable.ic_android_black_24dp, "Line 13", "Line 2"));
        exampleList.add(new ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 15", "Line 14"));
        exampleList.add(new ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 17", "Line 16"));
        exampleList.add(new ExampleItem(R.drawable.ic_android_black_24dp, "Line 19", "Line 18"));
        exampleList.add(new ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 21", "Line 20"));
        exampleList.add(new ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 23", "Line 22"));
        exampleList.add(new ExampleItem(R.drawable.ic_android_black_24dp, "Line 25", "Line 24"));
        exampleList.add(new ExampleItem(R.drawable.ic_audiotrack_black_24dp, "Line 27", "Line 26"));
        exampleList.add(new ExampleItem(R.drawable.ic_add_a_photo_black_24dp, "Line 29", "Line 30"));
        mRecyclerView = findViewById(R.id.recyclerView);
        mRecyclerView.setHasFixedSize(true);
        mLayoutManager = new LinearLayoutManager(this);
        new ItemTouchHelper(itemTouchHelperCallback).attachToRecyclerView(mRecyclerView);
        mAdapter = new ExampleAdapter(exampleList);
        mRecyclerView.setLayoutManager(mLayoutManager);
        mRecyclerView.setAdapter(mAdapter);
    }

    ItemTouchHelper.SimpleCallback itemTouchHelperCallback = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.RIGHT | ItemTouchHelper.LEFT) {
        @Override
        public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
            return false;
        }

        @Override
        public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
//            viewHolder.getAdapterPosition()
//            exampleList.remove(direction);
//            notifyItemRemoved()
//            mAdapter.removeAt(direction);
            mRecyclerView.setLayoutManager(mLayoutManager);
            mRecyclerView.setAdapter(mAdapter);
        }
    };

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.example_menu, menu);
        MenuItem searchItem = menu.findItem(R.id.action_search);
        SearchView searchView = (SearchView) searchItem.getActionView();
        searchView.setImeOptions(EditorInfo.IME_ACTION_DONE);
        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String s) {
                return false;
            }

            @Override
            public boolean onQueryTextChange(String s) {
                mAdapter.getFilter().filter(s);
                return false;
            }
        });
        return true;
    }

}
