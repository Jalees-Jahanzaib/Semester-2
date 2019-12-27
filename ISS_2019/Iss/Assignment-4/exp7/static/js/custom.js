/*!
 * Start Bootstrap - Freelancer Bootstrap Theme (http://startbootstrap.com)
 * Code licensed under the Apache License v2.0.
 * For details, see http://www.apache.org/licenses/LICENSE-2.0.
 */

// jQuery for page scrolling feature - requires jQuery Easing plugin
$(function() {
	$('body').on('click', '.page-scroll a', function(event) {
		var $anchor = $(this);
		$('html, body').stop().animate({
			scrollTop: $($anchor.attr('href')).offset().top
		}, 1500, 'easeInOutExpo');
		event.preventDefault();
	});
});

// Floating label headings for the contact form
$(function() {
	$("body").on("input propertychange", ".floating-label-form-group", function(e) {
		$(this).toggleClass("floating-label-form-group-with-value", !! $(e.target).val());
	}).on("focus", ".floating-label-form-group", function() {
		$(this).addClass("floating-label-form-group-with-focus");
	}).on("blur", ".floating-label-form-group", function() {
		$(this).removeClass("floating-label-form-group-with-focus");
	});
});

// Highlight the top nav as scrolling occurs
$('body').scrollspy({
	target: '.navbar-fixed-top'
})

// Closes the Responsive Menu on Menu Item Click
$('.navbar-collapse ul li a').click(function() {
	$('.navbar-toggle:visible').click();
});

$('#lang').val("default");


var que = new Array();
var ans = new Array();
var option = new Array();

function select2(){
	var i = 0;
	$('#sent').empty().append("<option value=\""+"-1"+"\" selected>---Select Sentence---</option>");
	que.forEach(function(item){
		$('#sent').append("<option value=\""+i+"\">"+item+"</option>");
		i++;
	});
	$('#sent').css({"display" : "block", "margin" : "10px auto","margin-bottom":"30px"}).show();
}

$('#lang').change(function(){
	var val = $('#lang').find(":selected").text();
	if(val == "English") val = 1;
	else if(val == "Hindi") val = 2;
	else val = 0;
	if(val != 0){
		$.ajax({
			data : {
				option : val,
			},
			type : 'POST',
			url  : '/form-exp1'  
		})
		.done(function(data){
			$('#exp-table').hide();
			$('#exp-table-heading').html("");
			$('#exp-submit').hide();
			$('#exp-get_ans').hide();
			if(data.message == 'Unable to fetch data!'){
				alert(data.message);
				return 0;
			}
			que = data.que;
			ans = data.ans;
			option = (data.option).split(",");
		   	select2();
		});
		event.preventDefault();
	}
	else{
		$('#sent').hide();
		$('#exp-table').hide();
		$('#exp-table-heading').html("");
		$('#exp-submit').hide();
		$('#exp-get_ans').hide();
	}

});

function select4(i){
	var x = "<select id=\"pos"+i+"\" class=\"pos\">";
	option.forEach(function(item){
		x += "<option>"+item+"</option>";
	});
	x+="</select>";
	return x;
}

function select3(val){
	var ar = new Array();
	ar = ans[val].split(" ");
	var i=0;
	ar.forEach(function(item){
		var x = item.split("/")[0];
		$('#exp-tbody').append("<tr><td class=\"col1\">"+x+"</td><td class=\"col2\">"+select4(i)+"</td><td id=\"pic"+i+"\" class=\"col3\"></td><td id=\"ans"+i+"\" class=\"col4\"></td></tr>");
		i++;
	});
	count = i;
	$('#exp-table').show();
	$('#exp-submit').show();
}

var value = 0;

$('#sent').change(function(){
	var val = $('#sent').find(":selected").val();
	value = val;
	if(val == "-1"){
		$('#exp-table').hide();
		$('#exp-table-heading').html("");
		$('#exp-submit').hide();
		$('#exp-get_ans').hide();
		return 0;
	}
	$('#exp-table-heading').html("Select the POS tag for corresponding words");
	$('#exp-tbody tr').remove();
	select3(parseInt(val));
});

$('#exp-submit').click(function(){
	var ar = new Array();
	ar = ans[value].split(" ");
	for(var i=0;i<ar.length;i++){
		if($("#pos"+i).find(":selected").text() == ar[i].split("/")[1]){
			$("#pic"+i).empty().append("<img src=\"static/images/right.png\" height=\"35px\" width=\"65px\">");
		}
		else{
			$("#pic"+i).empty().append("<img src=\"static/images/wrong.png\" height=\"35px\" width=\"65px\">");
		}
	}
	$("#exp-get_ans").show();
});

$('#exp-get_ans').click(function(){
	var ar = new Array();
	ar = ans[value].split(" ");
	for(var i=0;i<ar.length;i++){
		$("#ans"+i).html(ar[i].split("/")[1]);
	} 
});