import style from './UserChallengeSelect.module.css'
import { useNavigate, useParams } from 'react-router-dom'
import { useState, useEffect } from 'react'
import axios from 'axios';

const printChallengesData = (data, selectChallenge, challengeId) => {
  return (
    <div>
     {
      data.map( (item, index) => {
        return (
         <>
            <label className={style.sText}>
              <input type="radio" id={index} name="options" value={item["id"]} onChange={selectChallenge} checked={item["id"] === challengeId} /> Испытание {index+1}
            </label>
            <ul>
              <li key="a1">
                <label className={style.sText}>
                  Аннотация.
                </label>
                <li key="a2" className={style.textLiLi}>
                  {item["annotation"]}
                </li>
              </li>
              <li key="a3">
                <label className={style.sText}>
                  Содержание.
                </label>  {
                            item["subsection"].map( (item, index) => {
                              return(
                                <li key={index} className={style.textLiLi}>
                                  {item}
                                </li>
                              )
                            })
                          }
              </li>
              <li key="a4">
                <label className={style.sText}>
                  Количество вопросов:
                </label> {item["totalQuestions"]}
              </li>
              <li key="a5">
                <label className={style.sText}>
                  Время выполнения не более:
                </label> {item["maxTime"]} минут
              </li>
            </ul>
         </>
        )
      })
      }
    </div>
  )
}

const getSectionById = (id) => {
  switch (id){
    case 'safety':
      return "Безопасность жизнедеятельности"

    case 'phys':
      return "Физика"

    case 'math':
      return "Математика"

    case 'cognitive':
      return "Когнитивизм"

    case 'psychoanalysis':
      return "Психоанализ"

    case 'behaviourism':
      return "Бихевиоризм"

    case 'irony':
      return "Ирония"

    case 'satire':
      return "Сатира"

    case 'anekdots':
      return "Анекдоты"
    default:
      return "??"
  }
}

const UserChallengeSelect = () => {
  const navigate = useNavigate();
  const { sectionId } = useParams();
  const [section, setSection ] = useState(null)
  const [loading, setLoading] = useState(true);
  const [challengesData, setChallengesData] = useState(null)
  const [challengeId, setChallengedId] = useState(null);

  useEffect( () => {
    const fetchData = async () => {
    try {
      const response = await axios.get('http://5.188.51.63:7500/challenges');
      const dataAPI = response.data
      setSection(getSectionById(sectionId))
      const challenges = dataAPI.filter(item => item.section === section);
      if (challenges !== null && challenges !== undefined && challenges.length !== 0){
        const oldObj = JSON.stringify(challengesData)
        const newObj = JSON.stringify(challenges)
        if ( oldObj !== newObj){
          setChallengesData(challenges)
          setChallengedId(challenges[0]["id"])
        }
        setLoading(false)
      }
    }
    catch (error) {
      console.error('Error fetching data:', error);
      }
    };

  fetchData();
  }, [sectionId, section, challengesData, challengeId])


  const selectChallenge = (event) => {
    setChallengedId(event.target.value);
  }

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  const startChallenge = (event) => {
    const postData = async () => {
      try {
        console.log(challengeId)
        const postObj = {
          id: challengeId
        }
        const response = await axios.post('http://5.188.51.63:7500/session', postObj);
        console.log('Response:', response.data);
        // Move to test page
        navigate(`/user-passing-test/${response.data}`)

      } catch (error) {
        console.error('Error:', error);
      }
    }
    postData();
  }

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>{section}</div>
        <div className={style.text}>
          <div style={{ width: '40vw', height: '48vh', overflow: 'auto', border: '0px solid gray' }} >
          {printChallengesData(challengesData, selectChallenge, challengeId)}
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate(-1)} >Back</button>
          <button className={style.flatButton} onClick={ startChallenge } >Start testing</button>
        </div>
      </div>
  );
}

export default UserChallengeSelect;
