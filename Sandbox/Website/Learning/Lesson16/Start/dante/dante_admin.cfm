<cfquery name="rs_GetUsers" datasource="dante">
SELECT username, firstName, lastName
FROM users
ORDER BY lastName ASC
</cfquery>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/dante_template.dwt" codeOutsideHTMLIsLocked="false" -->
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<!-- InstanceBeginEditable name="head_title" -->
<title>Dante's Inferno: Admin</title>
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
		<h1><!-- InstanceBeginEditable name="page_heading" -->Dante's <em>Inferno</em>: Admin <!-- InstanceEndEditable --></h1>
   		<!-- InstanceBeginEditable name="main_content" -->
		
		<p>The following students are enrolled in the class.</p>
		
        <table border="1">
          <tr>
            <td><strong>Email Address</strong></td>
            <td><strong>First Name</strong></td>
            <td><strong>Last Name</strong></td>
          </tr>
          <cfoutput query="rs_GetUsers">
            <tr>
              <td><a href="mailto:#rs_GetUsers.username#">#rs_GetUsers.username#</a></td>
              <td>#rs_GetUsers.firstName#</td>
              <td>#rs_GetUsers.lastName#</td>
            </tr>
          </cfoutput>
        </table>
        <p><a href="index.cfm">Return</a> to the Dante site home page.</p>
  <!-- InstanceEndEditable -->
	</div>
</body>
<!-- InstanceEnd --></html>
