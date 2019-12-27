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

$('#lang').val("-1");


var cor = new Array();
var algo = new Array();
var train = new Array();

function select2(){
	var i = 0;
	$('#cor').empty().append("<option value=\""+"-1"+"\" selected>---Select Size of training Corpus---</option>");
	cor.forEach(function(item){
		$('#cor').append("<option value=\""+i+"\">"+item+"</option>");
		i++;
	});
	$('#cor').show();
}

$('#lang').change(function(){
	var val = $('#lang').find(":selected").val();
	if(val != -1){
		$.ajax({
			data : {
				option : 1
			},
			type : 'POST',
			url  : '/form-exp1'  
		})
		.done(function(data){
			$('#cor').hide();
			$('#algo').hide();
			$('#train').hide();
			$('#accuracy').hide();
			$('#ans').html("");
			$('#cor-tag').html("");
			$('#algo-tag').html("");
			$('#train-tag').html("");
			if(data.message == 'Unable to fetch data!'){
				alert(data.message);
				return 0;
			}
			$('#cor-tag').html("First step is to train a corpus, select the size of a corpus ");
			algo = data.algo;
			cor = data.cor;
			train = data.train;
		   	select2();
		});
		event.preventDefault();
	}
	else{
			$('#cor').hide();
			$('#algo').hide();
			$('#train').hide();
			$('#accuracy').hide();
			$('#ans').html("");
			$('#cor-tag').html("");
			$('#algo-tag').html("");
			$('#train-tag').html("");
	}

});


function select3(){
	var i = 0;
	$('#algo').empty().append("<option value=\""+"-1"+"\" selected>---Select algorithm for training---</option>");
	algo.forEach(function(item){
		$('#algo').append("<option value=\""+i+"\">"+item+"</option>");
		i++;
	});
	$('#algo').show();
}

$('#cor').change(function(){
	var val = $('#cor').find(":selected").val();
	if(val == "-1"){
			$('#algo').hide();
			$('#train').hide();
			$('#accuracy').hide();
			$('#ans').html("");
			$('#algo-tag').html("");
			$('#train-tag').html("");
		return 0;
	}
	$('#algo-tag').html("Select the algorithm for training");
	$('#ans').html("");
	select3();
});

function select4(){
	var i = 0;
	$('#train').empty().append("<option value=\""+"-1"+"\" selected>---Select feature for training---</option>");
	train.forEach(function(item){
		$('#train').append("<option value=\""+i+"\">"+item+"</option>");
		i++;
	});
	$('#train').show();
}

$('#algo').change(function(){
	var val = $('#algo').find(":selected").val();
	if(val == "-1"){
			$('#train').hide();
			$('#train-tag').html("");
			$('#accuracy').hide();
			$('#ans').html("");
		return 0;
	}
	$('#train-tag').html("Now, select feature for training");
	$('#ans').html("");
	select4();
});

$('#train').change(function(){
	var val = $('#train').find(":selected").val();
	if(val == "-1"){
			$('#accuracy').hide();
			$('#ans').html("");
		return 0;
	}
	$('#accuracy').show();
	$('#ans').html("");
});


$('#accuracy').click(function(){
	var ans=0;
	var x=$('#cor').find(":selected").val();
	var y=$('#algo').find(":selected").val();
	var z=$('#train').find(":selected").val();
	
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
    if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	if(x=="0" && y=="0" && z=="0"){
		ans=91.7;
	}
	
	
	$('#ans').html("Accuracy is: "+ans);
});