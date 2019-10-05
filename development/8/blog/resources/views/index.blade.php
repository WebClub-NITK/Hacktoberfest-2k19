@extends('layouts.app')

@section('content')
<div class="container">
    @if(!auth()->guest())
    <div class="row">
        <div class="col-md-8 offset-md-2">
            <a href="{{ route('posts.create') }}" class="btn btn-primary mb-2">+ New Post</a>
        </div>
    </div>
    @endif
    <div class="row">
        <div class="col-md-8 offset-md-2">
    @if ($posts->isEmpty())
    <div class="alert alert-secondary">No posts.</div>
    @else
    @foreach ($posts as $post)
            <div class="card mb-2">
                <h3 class="card-header">
                    <a href="{{ route('posts.show', ['id' => $post->id]) }}">{{ $post->title }}</a>
                    <span class="text-muted small">at {{ $post->created_at }}</span>
                </h3>
                <div class="card-body">{{ $post->content }}</div>
            </div>
        
    @endforeach
    @endif
        </div>
    </div>
</div>
@endsection
