var keyW = document.getElementById("w");
var keyA = document.getElementById("a");
var keyS = document.getElementById("s");
var keyD = document.getElementById("d");

var wPressed = false;
var aPressed = false;
var sPressed = false;
var dPressed = false;

var press;
var release;

document.onkeypress = function(event){
    key_operations(event);
};

document.onkeyup = function(event) {
    key_operations(event);
};


function key_operations(event){         //The main function dealing with key-operations, whether it be press or release of keys
    var key = event.key;
    if(event.type == "keypress"){
        press = true;
        release = false;
    }

    else if(event.type == "keyup"){
        release = true;
        press = false;
    }

    if((key == "w"||key == "W") && !sPressed){
        w_key();
    }

    else if((key == "a"||key == "A") && !dPressed){
        a_key();
    }

    else if((key == "s"||key == "S") && !wPressed){
        s_key();
    }

    else if((key == "d"||key == "D") && !aPressed){
        d_key();
    }
}

function w_key(){
    if(press == true){
        console.log("w")
        wPressed = true;
        keyW.style.color = "rgb(55, 54, 54)";
        keyW.style.backgroundColor = "white";
        changeDriveState(1);
    }

    else if(release == true){
        wPressed = false;
        keyW.style.color = "white";
        keyW.style.backgroundColor = "rgb(55, 54, 54)";
    }
}

function a_key(){
    if(press == true){
        console.log("a")
        aPressed = true;
        keyA.style.color = "rgb(55, 54, 54)";
        keyA.style.backgroundColor = "white";
        changeTurnState(1);
    }

    else if(release == true){
        aPressed = false;
        keyA.style.color = "white";
        keyA.style.backgroundColor = "rgb(55, 54, 54)";
    }
}

function s_key(){
    if(press == true){
        console.log("s")
        sPressed = true;
        keyS.style.color = "rgb(55, 54, 54)";
        keyS.style.backgroundColor = "white";
        changeDriveState(0);
    }

    else if(release == true){
        sPressed = false;
        keyS.style.color = "white";
        keyS.style.backgroundColor = "rgb(55, 54, 54)";
    }
}

function d_key(){
    if(press == true){
        console.log("d")
        dPressed = true;
        keyD.style.color = "rgb(55, 54, 54)";
        keyD.style.backgroundColor = "white";
        changeTurnState(0);
    }

    else if(release == true){
        dPressed = false;
        keyD.style.color = "white";
        keyD.style.backgroundColor = "rgb(55, 54, 54)";
    }
}