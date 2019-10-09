const Methods = {
  init() {
    Methods.opcoesComodo();
    Methods.checkboxActive();
    Methods.fireBaseInit();
  },
  fireBaseInit() {
    var config = {
      apiKey: "AIzaSyDo7pwae4rYsk8MuCIUj-KIuQewXy6YA40",
      authDomain: "node-mcu-firebase-b65a6.firebaseapp.com",
      databaseURL: "https://node-mcu-firebase-b65a6.firebaseio.com",
      projectId: "node-mcu-firebase-b65a6",
      storageBucket: "node-mcu-firebase-b65a6.appspot.com",
      messagingSenderId: "949815596056",
      appId: "1:949815596056:web:65a4b89e5dd02b00fe5f6d"
    };
    firebase.initializeApp(config);

    var database = firebase.database();

    function updateOnOff() {
      const labels = document.querySelectorAll('.label-led');
      labels.forEach(label => {
        label.addEventListener('click', function () {
          this.childNodes.forEach(child => {
            if(child.tagName == "INPUT") {
              child.checked ? database.ref(this.getAttribute('data-firebase')).set(1) : database.ref(this.getAttribute('data-firebase')).set(0);
            }
          })
          
        })
      })
    }

    function updateCanal() {
      const btn = document.querySelector('.canal.send');
      const valueTxt = document.querySelector('.display').value;
      btn.addEventListener('click', function() {
        console.log(database.ref("salaTv"))
        database.ref("salaTv").set(valueTxt);
      })
    }

    function updateTemperatura() {
      const btn = document.querySelector('.temperatura.send');
      const valueTxt = document.querySelector('.temperatura').value;
      btn.addEventListener('click', () => {
        database.ref("banheiroTemperatura").set(valueTxt);
      })
    }
    updateCanal();
    updateTemperatura();
    updateOnOff();
  },
  opcoesComodo() {
    const botoesMenu = document.querySelectorAll('.button-menu');
    botoesMenu.forEach(botao => {
      botao.addEventListener('click', () => {
        const menuClass = '.controle.' + botao.getAttribute('data-menu');
        const menus = document.querySelectorAll('.controle');
        menus.forEach(menu => {
          menu.classList.remove('is--active');
        })

        document.querySelector(menuClass).classList.toggle('is--active');
      })
    })
  },
  checkboxActive() {
    const checkbox = document.querySelectorAll('input[type=checkbox]');
    checkbox.forEach(checked => {
      checked.addEventListener('click', () => {
        checked.checked ? checked.parentNode.classList.add('is--active') : checked.parentNode.classList.remove('is--active');
      })
    })
  }
}

document.addEventListener('DOMContentLoaded', Methods.init);