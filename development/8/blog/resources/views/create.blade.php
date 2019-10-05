@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 offset-md-2">
            <h2>New Post</h2>
            <form action="{{ route('posts.store') }}" method="post">
            {{ csrf_field() }}
                <div class="form-row">
                    <label for="title">Title</label>
                    <input type="text" name="title" id="title" placeholder="An interesting title" class="form-control">
                    <span class="text-danger">{{ $errors->first('title') }}</span>
                </div>
                <div class="form-row">
                    <label for="content">Post Content</label>
                    <textarea name="content" id="content" cols="30" rows="10" class="form-control"></textarea>
                    <span class="text-danger">{{ $errors->first('content') }}</span>
                </div>
                <div class="form-row">
                    <button class="btn btn-primary" type="submit">Save</button>
                </div>
            </form>
        </div>
    </div>
</div>
@endsection