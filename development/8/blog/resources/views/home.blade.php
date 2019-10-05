@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 offset-md-2">
            <div class="jumbotron"><h1>Hacktoberfest 2019</h1></div>
        </div>
    </div>
    <div class="row">
        <div class="col-md-8 offset-md-2">
            <p>This is a project to resolve <a href="https://github.com/WebClub-NITK/Hacktoberfest-2k19/issues/8">Issue 8</a> of <a href="https://github.com/WebClub-NITK/Hacktoberfest-2k19">WebClub-NITK Hacktoberfest</a> party.</p>
            <p>This project used <a href="https://laravel.com/">Laravel</a>, a PHP framework, and <a href="https://getbootstrap.com/">Bootstrap</a>, a CSS framework, included on Laravel installation.</p>
            <h3>Description</h3>
            <p>Implement a website that allows you to post blogs with working authentication.</p>
            <h3>Details</h3>
            <ul>
                <li>Technical Specifications: Use any framework of your choice to implement the web app.</li>
                <li>Type of issue: Single</li>
                <li>Time Limit: 1 week</li>
            </ul>
            <h3>Issue requirements / progress</h3>
            <ul>
                <li>Decide upon a framework- django, expressjs, flask, etc and bootstrap the project</li>
                <li>Create the basic structure of the web site</li>
                <li>Add functionality to the website</li>
                <li>Add authentication system to the website</li>
                <li>Add styling to the website</li>
            </ul>
            <h3>How to use</h3>
            <p>Upon installation, a MySQL database must be created called <code>blog_auth</code>. Migrations have to be executed by the command <code>php artisan migrate</code>, this will create the database tables to store User and Post data.</p>
            <p>To access the blog, click on <a href="{{ route('posts.index') }}">Blog</a> at the right of the navbar on top.</p>
            <p>In order to create a blog post, user must access <a href="{{ route('posts.create') }}">/posts/create</a>. If not logged in, will require a username and password.</p>
            <p>A user can be created by clicking on <a href="{{ route('register') }}">Register</a> at the navbar.</p>
        </div>
    </div>
</div>
@endsection
