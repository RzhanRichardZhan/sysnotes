$(document).ready(function() {
    $("p").hide();
    $("h1").click(function(){
	$(this).next().slideToggle(300);
    });
    $("#test").click(function(){
	$("div h3").css("background-color","red");
    });

});
