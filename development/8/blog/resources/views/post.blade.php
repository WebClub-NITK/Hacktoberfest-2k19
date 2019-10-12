@extends('layouts.app')

@section('content')
<div class="jumbotron">
    <div class="container">
        <div class="row">
            <div class="col-md-8 offset-md-2">
                <h2>{{ $post->title }}</h2>
                <p>Author: {{ $author->name }}</p>
            </div>
            
        </div>
    </div>
</div>
<div class="container">
    <div class="row">
        <div class="col-md-8 offset-md-2">
            <div class="card">
                <div class="card-body">{{ $post->content }}</div>
            </div>
        </div>
    </div>
</div>
@endsection