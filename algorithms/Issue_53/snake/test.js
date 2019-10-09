"use strict";

// Vertex shader source
var vertexShaderSource = `#version 300 es
in vec2 a_position;
uniform vec2 u_resolution;

void main() {

    // Convert the position from pixels to clip space
    vec2 zeroToOne = a_position / u_resolution;
    vec2 zeroToTwo = zeroToOne * 2.0;
    vec2 clipSpace = zeroToTwo - 1.0;

    gl_Position = vec4(clipSpace, 0, 1);
}
`;

// Fragment shader source
var fragmentShaderSource = `#version 300 es
precision mediump float;
uniform vec4 u_color;
out vec4 outColor;
void main() {
    outColor = u_color;
}
`;

function createShader(gl, type, source) {
    var shader = gl.createShader(type);
    gl.shaderSource(shader, source);
    gl.compileShader(shader);
    var success = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
    if (success) {
        return shader;
    }
    console.log(gl.getShaderInfoLog(shader));
    gl.deleteShader(shader);
    return undefined;
}

function createProgram(gl, vertexShader, fragmentShader) {
    var program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    var success = gl.getProgramParameter(program, gl.LINK_STATUS);
    if (success) {
        return program;
    }
    console.log(gl.getProgramInfoLog(program));
    gl.deleteProgram(program);
    return undefined;
}

function main() 
{

	var score=0;
	document.getElementById("score").innerHTML = "<h2> Score : "+ score+"</h2>";
    // Get WebGL context
    var canvas = document.getElementById("c");
    var gl = canvas.getContext("webgl2");
    if (!gl) {
        return;
    }
    gl.canvas.width  = window.innerWidth;
    gl.canvas.height = window.innerHeight;
    // Create and compile the shaders
    var vertexShader = createShader(
        gl, gl.VERTEX_SHADER, vertexShaderSource);
    var fragmentShader = createShader(
        gl, gl.FRAGMENT_SHADER, fragmentShaderSource);

    // Link the shaders into a program
    var program = createProgram(gl, vertexShader, fragmentShader);

    // Create a buffer and bind it to ARRAY_BUFFER 
    var positionBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);

    // Copy data from JavaScript array to ARRAY_BUFFER i.e. positionBuffer
    var positions = [
        10, 20,
        80, 20,
        10, 30,
        10, 30,
        80, 20,
        80, 30,
    ];

    gl.bufferData(gl.ARRAY_BUFFER, 
        new Float32Array(positions), gl.STATIC_DRAW);

    // Create a VAO and bind it
    var vao = gl.createVertexArray();
    gl.bindVertexArray(vao);

    // Specify where the data in the positionBuffer needs to go
    var positionAttributeLocation = 
            gl.getAttribLocation(program, "a_position");
    gl.enableVertexAttribArray(positionAttributeLocation	);

    // Specify how to pull the data out of the positionBuffer
    var size = 2;
    var type = gl.FLOAT;
    var normalize = false;
    var stride = 0;
    var offset = 0;
    gl.vertexAttribPointer(
        positionAttributeLocation, size, type, normalize, stride, offset);

    // Get location of uniform variable u_resolution
    var resolutionUniformLocation 
        = gl.getUniformLocation(program, "u_resolution");

    // Resize the canvas to the display size specified in CSS
    webglUtils.resizeCanvasToDisplaySize(gl.canvas);

    // Tell WebGL how to convert from clip space to screen space
    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height);

    // Clear the canvas
    gl.clearColor(0, 0, 0, 1);
    gl.clear(gl.COLOR_BUFFER_BIT);

    // Tell to use the program that we created
    gl.useProgram(program);

    // Bind the VAO 
    gl.bindVertexArray(vao);

    // Pass canvas resolution using the uniform variable
    gl.uniform2f(resolutionUniformLocation, gl.canvas.width, gl.canvas.height);

    var colorLocation = gl.getUniformLocation(program, "u_color");
    var x = 0, y = 0, w = 80, h = 20;
    // x and y are the coordinates of the head of the snake.
    setRectangle(gl, x, y, 20, 20);
    gl.uniform4f(colorLocation,0,0.5,0, 0.5);
    var primitiveType = gl.TRIANGLES;
    var offset = 0;
    var count = 6;
    gl.drawArrays(primitiveType, offset, count);

    // food coordinates
    var foodposx=Math.floor(randomInt(780)/20)*20
    var foodposy=Math.floor(randomInt(580)/20)*20;

    // Next 5 lines are used for essentially creating the food
    setRectangle(gl, foodposx, foodposy, 20, 20);
    gl.uniform4f(colorLocation,0.5, 0,0, 0.5);
    var primitiveType = gl.TRIANGLES;
    var offset = 0;
    var count = 6;
    gl.drawArrays(primitiveType, offset, count);

    // This flag=2 indicates that snake is moving towards right.
    // flag=1 -> left
    // flag=3 -> up
    // flag=4 -> down
    var flag=2;
    // Initilaise snake's length
    var snakelength=1;
    // posx[i] and posy[i] are the coordinates of the ith part of the snake
    // Starting from posx[0],posy[0] which is the head of the snake
    var posx=[],posy=[];

    //posx[0] and posy[0] are assigned the snake head coordinates i.e x and y respectively.
    posx[0]=x;
    posy[0]=y;
    
    var interval = setInterval(function(){
    	gl.clearColor(0, 0, 0, 1);
    	gl.clear(gl.COLOR_BUFFER_BIT);

        // The following loop indicates that ith part follows i-1th 
        // for i>0
    	var i;
    	for(i=snakelength-1; i>0; i--){
    		posx[i]=posx[i-1];
    		posy[i]=posy[i-1];
    	}
    	
        // This condition sets the head after its subsequent parts are set above
    	if(flag==1){
    		x -= 20;
    		if (x < 0) x=780;
    	}else if (flag==2){
    		x += 20;
            if (x>780) x=0;
    	}else if (flag==3){
    		y += 20;
            if (y>580) y=0;
    	}else if (flag==4){
    		y -= 20;
            if (y<0) y=580;
    	}

        //If head meets food the following is executed
    	if(foodposy==y && foodposx==x){
			foodposx = Math.floor(randomInt(780)/20)*20;
			foodposy = Math.floor(randomInt(580)/20)*20;
			score+=10;
			snakelength+=1;
			document.getElementById("score").innerHTML = "<h2> Score : "+ score+"</h2>";
		}
        // posx[0] and posy[0] are updated with x and y respectively.
		posx[0]=x;
		posy[0]=y;
        

        // Add your termination condition here

    	// The following loop is used draw all the parts of snake onto canvas
    	for(i=0; i<snakelength; i++){
	        setRectangle(gl, posx[i], posy[i], 20, 20);
	        gl.uniform4f(colorLocation,0,0.5,0, 0.5);
	        var primitiveType = gl.TRIANGLES;
	        var offset = 0;
	        var count = 6;
	        gl.drawArrays(primitiveType, offset, count);
	    }
        // the following is used to draw food onto the canvas
	    setRectangle(gl, foodposx, foodposy, 20, 20);
        gl.uniform4f(colorLocation,0.5, 0,0, 0.5);
        var primitiveType = gl.TRIANGLES;
        var offset = 0;
        var count = 6;
        gl.drawArrays(primitiveType, offset, count);
    },100);
    // Canvas will be redrawn every 100ms
    // This listens to the 'keydown' event from your Keyboard.
    // The following keyCode are keyCodes of up, down, left and right.
    //
    window﻿﻿.addEventListener('keydown', function (event)﻿
    {

    	var i;

        if (event.keyCode === 37 && flag!=1 && flag!=2 ) { // Left
            // before moving the head to this direction, we first update the following parts of the snake
        	for(i=snakelength-1; i>0; i--){
        		posx[i]=posx[i-1];
        		posy[i]=posy[i-1];
        	}
        	x -= 20;
        	if (x < 0) x=780;
        	flag = 1;
        }
        else if (event.keyCode === 39 && flag!=1 && flag!=2 ) { // Right
        	for(i=snakelength-1; i>0; i--){
        		posx[i]=posx[i-1];
        		posy[i]=posy[i-1];
        	}
        	x += 20;
            if (x>780) x=0;
            flag = 2;
        }
        else if (event.keyCode === 38 && flag!=3 && flag!=4 ) { // Up
        	for(i=snakelength-1; i>0; i--){
        		posx[i]=posx[i-1];
        		posy[i]=posy[i-1];
        	}
            y += 20;
            if (y>580) y=0;
            flag = 3;
        }
        else if (event.keyCode === 40 &&  flag!=3 && flag!=4 ) {// Down
        	for(i=snakelength-1; i>0; i--){
        		posx[i]=posx[i-1];
        		posy[i]=posy[i-1];
        	}
            y -= 20;
            if (y<0) y=580;
            flag = 4;
        }
        // posx[0] and posy[0] are updated with x and y respectively.
        posx[0]=x;
        posy[0]=y;

       
        // Add your termination condition here.

        //If head meets food the following is executed
        if(foodposy==y && foodposx==x){
        	foodposx = Math.floor(randomInt(780)/20)*20;
        	foodposy = Math.floor(randomInt(580)/20)*20;
        	score+=10;
        	snakelength+=1;
        	document.getElementById("score").innerHTML = "<h2> Score : "+ score+"</h2>";
        }

        // The following loop is used draw all the parts of snake onto canvas
        gl.clearColor(0, 0, 0, 1);
    	gl.clear(gl.COLOR_BUFFER_BIT);
    	var i;
    	for(i=0; i<snakelength; i++){
	        setRectangle(gl, posx[i], posy[i], 20, 20);
	        gl.uniform4f(colorLocation,0,0.5,0, 0.5);
	        var primitiveType = gl.TRIANGLES;
	        var offset = 0;
	        var count = 6;
	        gl.drawArrays(primitiveType, offset, count);
	    }
        
        // the following is used to draw food onto the canvas
        setRectangle(gl, foodposx, foodposy, 20, 20);
        gl.uniform4f(colorLocation,0.5, 0,0, 0.5);
        var primitiveType = gl.TRIANGLES;
        var offset = 0;
        var count = 6;
        gl.drawArrays(primitiveType, offset, count);
    });
}

function randomInt(range) {
    return Math.floor(Math.random() * range);
}

function setRectangle(gl, x, y, width, height) {
  var x1 = x;
  var x2 = x + width;
  var y1 = y;
  var y2 = y + height;
 
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([
     x1, y1,
     x2, y1,
     x1, y2,
     x1, y2,
     x2, y1,
     x2, y2]), gl.STATIC_DRAW);
}

function reload(){
	location.reload();
	document.getElementById("retry").innerHTML = "";
}


main();
