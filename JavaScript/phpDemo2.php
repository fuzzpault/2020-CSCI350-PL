<?php
    // https://docs.aws.amazon.com/cloud9/latest/user-guide/sample-lamp.html
    // We won't need MySQL for this
    // httpd & php seem to already be installed - Jump to step 5
    
    session_start();

  if(isset($_GET['type'])){
      echo $_GET['type'], "h";
      if( !isset($_SESSION['past'])){
          $_SESSION['past'] = 1;
      }
      $_SESSION['past'] += 1;
      exit();
  }
?>

<html>
    <head>
        <title>Stuff here</title>
        <script>
            function letterTyped(){
                sofar = document.getElementById('name').value;
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function(){
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById('box').innerHTML = this.responseText;
                    }
                }
                xhttp.open("GET", "/index.php?type=" + sofar)
                xhttp.send()
            }
            
        </script>
    </head>
    <body>
        <h1>This is an awesome page!</h1>
        
<?php
    for($i = 0; $i < 10; $i++){
        echo 'Stuff', $i, "<br>";
    }
    echo $_SESSION['past'];
?>

<form method="get" action=".">
    <label>Name: </label><input name="n" onkeyup="letterTyped()" id="name">
    <label>Age: </label> <input name="age">
    <input type="submit">
    
</form>

<p id="box"></p>

</body>
<?php
  if( isset($_GET["age"]) && $_GET["age"] < 40){
    echo "Your age is " , $_GET["age"], " and you are not old YET";
  }else{
      echo "You are old!";
  }
  
  phpinfo();
?>

</html>