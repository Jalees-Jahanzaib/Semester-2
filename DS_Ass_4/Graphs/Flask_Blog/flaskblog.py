from flask import Flask, render_template,url_for
from forms import RegistrationForm,LoginForm
app = Flask(__name__)
app.config['Secret_Key']= '0c8e85a1331f2b10be5abc827aae72cb'
posts = [
{
'author':'jalees',
'title':'Blog Post 1',
'content':'First Post content',
'date_posted':'22:May:2018'

},
{
'author':'jamy',
'title':'Blog Post 2',
'content':'Seconnd Post content',
'date_posted':'22:May:2018'


}

]
@app.route("/")
@app.route("/home")
def home():
	return render_template('home.html',posts=posts)
@app.route("/about")
def about():
	return render_template('about.html',title=About)
@app.route("/register")
def register():
	form=RegistrationForm()
	return render_template('register.html',title='Register',form=form)
@app.route("/login")	
def login():
	form=LoginForm()
	return render_template('login.html',title='login',form=form)	

if __name__ == '__main__':
	app.run(debug=True)