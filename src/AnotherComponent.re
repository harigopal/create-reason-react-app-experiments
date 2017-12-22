type appState = {
  people: int,
  favFood: string
};

type action =
  | IncrementPeople;

let component = ReasonReact.reducerComponent("AnotherComponent");

let make = (_children) => {
  {
    ...component,
  initialState: () => {
    { people: 0, favFood: "Cake" }
  },
  reducer: (action, state) => {
    switch(action) {
    | IncrementPeople => ReasonReact.Update({...state, people: state.people + 1})
    }
  },
  render: (self) => {
    let incrementPeople = (_event) => { 
      self.reduce((_event) => IncrementPeople )
      ()
    };
    let peopleCount = string_of_int(self.state.people);
    let peopleMessage = <span> {ReasonReact.stringToElement("The number of people is: " ++ peopleCount) }</span>;

     <div> <div> {ReasonReact.stringToElement("Hello there. Does this work?")} </div>
     <button onClick=incrementPeople>{ReasonReact.stringToElement("Increment peeps")}</button>
   <div> {peopleMessage}</div>
   </div> }
  }
};