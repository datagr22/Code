var keyW = document.getElementById("w");  // defines the W key on the keyboard as a variable
var keyA = document.getElementById("a");  // defines the A key on the keyboard as a variable
var keyS = document.getElementById("s");  // defines the S key on the keyboard as a variable
var keyD = document.getElementById("d");  // defines the D key on the keyboard as a variable

var txtbx = document.getElementById("textbox");  // defines the textbox on the website as a variable
var txt = "";  // the text showed in the textbox, appendable in the code
 
var wPressed = false;   // variable for button-pressed value (W) starts as false (0)
var aPressed = false;   // variable for button-pressed value (A) starts as false (0)
var sPressed = false;   // variable for button-pressed value (S) starts as false (0)
var dPressed = false;   // variable for button-pressed value (D) starts as false (0)

var press;   // variables for whether the key is pressed or released
var release;


document.onkeypress = function(event){  // when a key is pressed, run key operations accompanied by the event-tag 
    key_operations(event);
};

document.onkeyup = function(event) {   // same here
    key_operations(event);
};


function key_operations(event){         // The main function dealing with key-operations, whether it be press or release of keys
    var key = event.key;    //  store the key pressed in the variable "key"
    if(event.type == "keypress"){   //  if the event-tag shows a key has been pressed, define this by changing the variables "press" and "release"
        press = true;
        release = false;
    }

    else if(event.type == "keyup"){  // if the event-tag shows a key has been released, define this by changing "press" and "release"
        release = true;
        press = false;
    }

    if((key == "w"||key == "W") && !sPressed){  //  An if-structure redirects to the correct function based on what key was pressed, for simplicity arranged so that w and s, together with a and d cannot be pressed at the same time
        w_key();   //  Run the w_key-function on "w"-press
    }

    else if((key == "a"||key == "A") && !dPressed){  // same logic here
        a_key();
    }

    else if((key == "s"||key == "S") && !wPressed){  // and here
        s_key();
    }

    else if((key == "d"||key == "D") && !aPressed){  //and here
        d_key();
    }
}

//FORWARD
function w_key(){ // defines a function for each key, thats runs if the button is pressed and/or released. Logs x in the console changes value of xPressed , changes the appearence of the key and changes a state according to the key
    if(press == true && !wPressed){   //when "w" is pressed, run this if-segment, the boolean helps the code only run once, so that the server is not "spammed" with state-changes
        console.log("w")  // For debugging purposes, redundant functionality-wise
        wPressed = true;  // Changes the boolean so that this if-segment is only ran once, and s cannot be pressed (see function key_operations)
        keyW.style.color = "rgb(55, 54, 54)";   //  changes the color of the key on the interface, to indicate that it is, in fact pressed
        txt += "Forward drive\n";  // append this text describing the action to the log-text
        txtbx.innerHTML = txt;   // change the actual text in the log-textarea
        keyW.style.backgroundColor = "white";   //  change the color of the font embedded in the button to indicate that it is pressed
        changeDriveState(1);   //  changes the actual drive state, what makes the car actually move, through the socket and server
    }

    else if(release == true){  // in the instance that the button is released
        wPressed = false;  // change the boolean
        keyW.style.color = "white";  //back to original colors
        keyW.style.backgroundColor = "rgb(55, 54, 54)"
        changeDriveState(0);  // change the drive state, so that the car stops driving
    }
 txtbx.scrollTop = txtbx.scrollHeight  // auto-scroll in the log-textarea
}

//TURN LEFT
function a_key(){  //Same logic here
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

//REVERSE
function s_key(){  // And here
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

//TURN RIGHT
function d_key(){  // And here
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
