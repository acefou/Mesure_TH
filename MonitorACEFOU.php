<!DOCTYPE html>
<html>
  <head>
    <title>Monitor ACEFOU</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>    
	<link rel="stylesheet" type="text/css" href="style.css">
  </head>
  <body>
	<h1>Monitor ACEFOU</h1>
	<h2><?php include('acqact.php'); ?></h2>
	<div class="ex1"><?php include('acqthact.php'); ?></div>
	<div class="ex1"><?php include('acqhuact.php'); ?></div>
	<a href=listt.php><button type="button" class="btn btn-primary btn-lg btn-block">Historique des 5 derniers jours</button></a>
    <p>propulsé par ACEFOU</p>
  </body>
</html>
