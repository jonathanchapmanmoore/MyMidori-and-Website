<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/dante_template.dwt" codeOutsideHTMLIsLocked="false" -->
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<!-- InstanceBeginEditable name="head_title" -->
<title>Dante's Inferno: Quiz Login</title>
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
		<h1><!-- InstanceBeginEditable name="page_heading" -->Dante's <em>Inferno</em>: Quiz Login <!-- InstanceEndEditable --></h1>
   		<!-- InstanceBeginEditable name="main_content" -->
		
		<p>Take this ungraded quiz to see how well you’ve mastered the material.</p>
		
		<p>To access the quiz, please login below.</p>
		
		<p>
			<cfform action="dante_quiz_questions.cfm" method="post" name="frm_login" preloader="no" format="flash" skin="halogreen">
				<cfinput type="text" name="username" label="Email Address" validateat="onSubmit" validate="email" required="yes" size="30">
				<cfinput type="submit" name="Submit" value="Submit">
			</cfform>
		</p>
		
		<p><a href="index.cfm">Return</a> to the Dante site home page.</p>
		 
		<!-- InstanceEndEditable -->
	</div>
</body>
<!-- InstanceEnd --></html>
