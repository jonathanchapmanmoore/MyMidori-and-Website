<!DOCTYPE html>
<html>
<head>
	<title>A Sandcastle Documented Class Library - Search</title>
	<link rel="stylesheet" type="text/css" href="styles/branding.css" />
	<link rel="stylesheet" type="text/css" href="styles/branding-Website.css" />
	<script type="text/javascript" src="scripts/jquery-3.3.1.min.js"></script>
	<script type="text/javascript" src="scripts/branding.js"></script>
	<script type="text/javascript" src="scripts/branding-Website.js"></script>
</head>
<body onload="OnSearchPageLoad();">
	<div class="pageHeader" id="PageHeader">
		A Sandcastle Documented Class Library - Search
	</div>
	<div class="pageBody">
		<div class="searchContainer">
			<div style="float: left;">
				<form id="SearchForm" method="get" action="#" onsubmit="javascript:PerformSearch(); return false;">
				<input id="txtSearchText" type="text" maxlength="200" />
				<button id="HeaderSearchButton" type="submit" class="header-search-button">
				</button>
				</form>
			</div>
			&nbsp;&nbsp;<input type="checkbox" id="chkSortByTitle" onclick="javascript:PerformSearch();" />
			Sort by title
			<br />
			<br />
			<div id="searchResults">
			</div>
			<p>
				<a href="html/7a6dd06a-7731-430d-9620-dda79d396e7a.htm">Back</a></p>
		</div>
	</div>
</body>
</html>
