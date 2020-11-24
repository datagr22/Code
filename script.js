var keyW = document.getElementById("w");  // defines the W key on the keyboard as a variable
var keyA = document.getElementById("a");  // defines the A key on the keyboard as a variable
var keyS = document.getElementById("s");  // defines the S key on the keyboard as a variable
var keyD = document.getElementById("d");  // defines the D key on the keyboard as a variable

var txtbx = document.getElementById("textbox");
var txt = "";
 
var wPressed = false;   // variable for button-pressed value (W) starts as false (0)
var aPressed = false;   // variable for button-pressed value (A) starts as false (0)
var sPressed = false;   // variable for button-pressed value (S) starts as false (0)
var dPressed = false;   // variable for button-pressed value (D) starts as false (0)

var press;
var release;


document.onkeypress = function(event){
    key_operations(event);
};

document.onkeyup = function(event) {
    key_operations(event);
};


function key_operations(event){         // The main function dealing with key-operations, whether it be press or release of keys
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

function w_key(){ // defines a function for each key, thats runs if the button is pressed and/or released. Logs x in the console changes value of xPressed , changes the appearence of the key and changes a state according to the key
    if(press == true && !wPressed){
        console.log("w")
        wPressed = true;
        keyW.style.color = "rgb(55, 54, 54)";
        txt += "Forward drive\n";
        txtbx.innerHTML = txt;
        keyW.style.backgroundColor = "white";
        changeDriveState(1);
    }

    else if(release == true){
        wPressed = false;
        keyW.style.color = "white";
        keyW.style.backgroundColor = "rgb(55, 54, 54)"
        changeDriveState(0);
    }
 txtbx.scrollTop = txtbx.scrollHeight
}

function a_key(){
    if(press == true && !aPressed){
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
        txt += "Left turn\n";
        txtbx.innerHTML = txt;
        changeTurnState(0);
    }
 txtbx.scrollTop = txtbx.scrollHeight
}

function s_key(){
    if(press == true && !sPressed){
        console.log("s")
        sPressed = true;
        keyS.style.color = "rgb(55, 54, 54)";
        keyS.style.backgroundColor = "white";
        changeDriveState(-1);
    }

    else if(release == true){
        sPressed = false;
        keyS.style.color = "white";
        keyS.style.backgroundColor = "rgb(55, 54, 54)";
        txt += "Reverse drive\n";
        txtbx.innerHTML = txt;
        changeDriveState(0);
    }
 txtbx.scrollTop = txtbx.scrollHeight
}

function d_key(){
    if(press == true && !dPressed){
        console.log("d")
        dPressed = true;
        keyD.style.color = "rgb(55, 54, 54)";
        keyD.style.backgroundColor = "white";
        changeTurnState(-1);
    }

    else if(release == true){
        dPressed = false;
        keyD.style.color = "white";
        keyD.style.backgroundColor = "rgb(55, 54, 54)";
        txt += "Right turn\n";
        txtbx.innerHTML = txt;
        changeTurnState(0);
    }
 txtbx.scrollTop = txtbx.scrollHeight
}
