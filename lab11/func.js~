function valUsername()
{
  if(event.keyCode >=48 & event.keyCode<=57)
  {
    event.returnValue=false;
  }
}
function validateForm()
{
  var y=document.getElementById("username").value;
  if (y.length==0)
      alert("username cannot be empty!");
  else
  {
  var x=document.getElementById("password").value;
    if (x.length<=4) 
	alert("password must be more than 4 chars!");
    else
      if(!((x.charCodeAt(0)>=65 && x.charCodeAt(0) <=90) || (x.charCodeAt(0)>=97 && x.charCodeAt(0) <=122)))
	alert("first character of password must be a letter!");
      else
	document.forms["form"].submit();
  }
}

function showHint(str){
  var xmlhttp;
  if (str.length==0){ 
	  
  document.getElementById("txtHint").innerHTML="";
	return;
      }

  if (window.XMLHttpRequest){// IE7+,Firefox,Chrome,Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
  else{// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.onreadystatechange=function(){
  if (xmlhttp.readyState==4 &&xmlhttp.status==200){
  document.getElementById("txtHint").innerHTML=xmlhttp.responseText;
  }
  }

  xmlhttp.open("GET","http://www.cs.bgu.ac.il/~chenisr/suggest.php?q="+str,true);
  xmlhttp.send();
}

