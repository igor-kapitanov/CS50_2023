from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
    #if "name" in request.args:
        #name = request.args["name"]
    #else:
        #name = "world"
    #name = request.args.get("name", "world")
    #return render_template("index.html")

