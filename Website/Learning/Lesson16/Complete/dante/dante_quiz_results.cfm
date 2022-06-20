<cfquery name="insertQuizScores" datasource="dante">
	INSERT INTO quiz
	(
	username,
	score
	)
	VALUES
	(
	'#form.username#',
	'#form.score#'
	)
</cfquery>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/dante_template.dwt" codeOutsideHTMLIsLocked="false" -->
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<!-- InstanceBeginEditable name="head_title" -->
<title>Dante's Inferno: Quiz Results</title>
<!-- InstanceEndEditable -->
<link rel="stylesheet" type="text/css" href="css/dante.css">
<!-- InstanceBeginEditable name="head" --><!-- InstanceEndEditable -->
</head>
<body>
	<div id="leftLogo"></div>
	<div id="inferno"><a href="index.cfm"></a></div>
	<div id="rightLogo"></div>
	<br clear="left" />
<div id="mainBody">
		<h1><!-- InstanceBeginEditable name="page_heading" -->Dante's <em>Inferno</em>: Quiz Results <!-- InstanceEndEditable --></h1>
   		<!-- InstanceBeginEditable name="main_content" -->
		
		<p>Thank you for taking the quiz, <strong><cfoutput>#Form.username#</cfoutput></strong></p>
		<p>Your score is: <strong><cfoutput>#Form.score#</cfoutput></strong> out of 5.</p>
		<p><a href="index.cfm">Return</a> to the Dante site home page.</p>
   		<!-- InstanceEndEditable -->	</div>
</body>
<!-- InstanceEnd --></html>
