<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', 'HomeController@index');

// Route::resource('posts', 'PostController')->only(['index', 'show']);

// Route::resource('posts', 'PostController')->only([
//     'create', 'store', 'update', 'destroy'
// ])->middleware('auth');

Route::middleware(['auth'])->group(function() {
    Route::view('/posts/create', 'create')->name('posts.create');
    // Route::get('/posts/create', 'PostController@create')->name('posts.create');
    Route::post('/posts', 'PostController@store')->name('posts.store');
    Route::delete('/posts/{id}', 'PostController@destroy')->name('posts.destroy');
    Route::patch('/posts/{id}', 'PostController@update')->name('posts.update');
});
Route::get('/posts', 'PostController@index')->name('posts.index');
Route::get('/posts/{id}', 'PostController@show')->name('posts.show');

Auth::routes();